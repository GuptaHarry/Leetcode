#include <bits/stdc++.h>
using namespace std;

class MovieRentingSystem {
private:
    unordered_map<int, unordered_map<int,int>> priceLookup; // shop -> movie -> price
    unordered_map<int, set<pair<int,int>>> available;       // movie -> set of {price, shop}
    set<tuple<int,int,int>> rented;                         // set of {price, shop, movie}

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto &e : entries){
            int shop = e[0], movie = e[1], price = e[2];
            priceLookup[shop][movie] = price;
            available[movie].insert({price, shop});
        }
    }

    vector<int> search(int movie) {
        vector<int> ans;
        if(available.count(movie)) {
            for(auto it = available[movie].begin(); it != available[movie].end() && ans.size() < 5; ++it){
                ans.push_back(it->second); // shop
            }
        }
        return ans;
    }

    void rent(int shop, int movie) {
        int price = priceLookup[shop][movie];
        available[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }

    void drop(int shop, int movie) {
        int price = priceLookup[shop][movie];
        rented.erase({price, shop, movie});
        available[movie].insert({price, shop});
    }

    vector<vector<int>> report() {
        vector<vector<int>> ans;
        int count = 0;
        for(auto it = rented.begin(); it != rented.end() && count < 5; ++it, ++count){
            int shop = get<1>(*it);
            int movie = get<2>(*it);
            ans.push_back({shop, movie});
        }
        return ans;
    }
};

/**
 * Example Usage:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop, movie);
 * obj->drop(shop, movie);
 * vector<vector<int>> param_4 = obj->report();
 */
