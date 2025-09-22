// Author  :   Vicen-te
// Date    :   09/22/2025 (MM-DD-YYYY)

/*
    Description:
        A movie renting system manages n shops and supports searching, renting, and returning movies.

        Each shop has at most one copy of each movie. 

        The system can list the cheapest 5 available copies, rent or drop movies, 
        and report the cheapest 5 currently rented movies. 

        Shops and movies are sorted by price, shop ID, and movie ID in case of ties.
    
        Ex:
            Input:
            ["MovieRentingSystem", "search", "rent", "rent", "report", "drop", "search"]
            [[3, [[0,1,5],[0,2,6],[0,3,7],[1,1,4],[1,2,7],[2,1,5]]], [1], [0,1], [1,2], [], [1,2], [2]]

            Output:
            [null, [1,0,2], null, null, [[0,1],[1,2]], null, [0,1]]

    Algorithm: 

        The solution relies on choosing the right data structures:
            - Nested map stores movie prices per shop.
            - Map tracks available movies.
            - Tuple tracks rented movies.

        Sets use the default comparator `std::less<Key>` to keep elements 
        sorted by the `<` operator (pairs: price then shop; tuples: price, shop, movie), 
        enabling efficient top-5 queries, inserts, and deletions.
        
        Time Complexity:
            - Constructor:  O(E log E)  -> builds the initial sets
            - search:       O(1)        -> only top 5 shops
            - rent / drop:  O(log n)    -> insert/erase in sorted sets
            - report:       O(1)        -> only top 5 rented movies

        Space Complexity: O(N)
*/

class MovieRentingSystem 
{
private: 

    unordered_map<int, unordered_map<int,int>> shops; // shops[shop][movie] -> price
    unordered_map<int, set<pair<int,int>>> available; // available[movie] -> (price, shop)
    set<tuple<int,int,int>> rented; // (price, shop, movie)

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) 
    {
        shops.reserve(n); 
        for (const auto& entry : entries) 
        {
            int shop = entry[0], movie = entry[1], price = entry[2];

            unordered_map<int,int>& shop_map = shops[shop];
            shop_map.emplace(movie, price);

            available[movie].emplace(price, shop);
        }
    }
    
    vector<int> search(int movie) 
    {
        vector<int> result;
        const set<pair<int,int>>& available_movies = available[movie];
        const int available_movies_size = min(5, static_cast<int>(available_movies.size()));
        result.reserve(available_movies_size);

        auto it = available_movies.begin();
        for (int i = 0; i < available_movies_size; ++i, ++it) 
        {
            result.push_back(it->second);
        }
        return result;
    }
    
    void rent(int shop, int movie) 
    {
        int price = shops[shop][movie];
        available[movie].erase({price, shop});
        rented.emplace(price, shop, movie);
    }
    
    void drop(int shop, int movie) 
    {
        int price = shops[shop][movie];
        rented.erase({price, shop, movie});
        available[movie].emplace(price, shop);
    }
    
    vector<vector<int>> report() 
    {
        vector<vector<int>> result;
        const int rented_movies_size = min(5, static_cast<int>(rented.size()));
        result.reserve(rented_movies_size);

        auto it = rented.begin();
        for (int i = 0; i < rented_movies_size; ++i, ++it) 
        {
            const tuple<int,int,int>& current = *it;
            result.push_back({get<1>(current), get<2>(current)});
        }
        return result;
    }
};


/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */