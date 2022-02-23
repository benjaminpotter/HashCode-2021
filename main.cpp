#include <map>
#include <string>
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main() {

    FILE* fp = fopen("d.in", "r");

    int clients;
    fscanf(fp, "%d", &clients);

    // map/dictionary: key -> value
    map<string, int> toppings;
    for(int i = 0; i < clients; i++) {

        int l;
        fscanf(fp, "%d", &l);
        for(int j=0; j < l; j++) {
            char top[25];
            fscanf(fp, "%s", &top);
            if (toppings.count(top) > 0){
                toppings.at(top) += 1;
            } else {
                toppings.insert( pair<string, int>(top, 1) );
            }
        }

        int d;
        fscanf(fp, "%d", &d);
        for(int j=0; j < d; j++) {
            char top[25];
            fscanf(fp, "%s", &top);
            if (toppings.count(top) > 0) {
                toppings.at(top) -= 1;
            } else {
                toppings.insert(pair<string, int>(top, -1));
            }
        }
    }

    vector<string> best;
    for (const auto& n : toppings) {
        if(n.second > 0)
            best.push_back(n.first);

        //std::cout << n.first << " = " << n.second << "; ";
    }

    fclose(fp);
    fp = fopen("d.out", "w");
    fprintf(fp, "%d", best.size());
    for(auto top : best) {
        fprintf(fp, " %s", top.c_str());
    }
    return 0;
}
