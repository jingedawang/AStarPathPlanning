//
// Created by wjg on 18-4-26.
//

#ifndef ASTARPATHPLANNING_UTILS_H
#define ASTARPATHPLANNING_UTILS_H

#include <vector>
#include <fstream>
#include <json/json.h>
#include <AStarSearch.h>

using namespace std;

class Utils {

public:

    static void toJsonFile(const string &filename,
                           const int height,
                           const int width,
                           const vector<SquareGrid::Location>& path,
                           const SquareGrid::Location& startPoint,
                           const SquareGrid::Location& destinationPoint,
                           const unordered_set<SquareGrid::Location>& obstacles)
    {
        Json::Value root;
        root["height"] = height;
        root["width"] = width;
        Json::Value arrayObj;
        Json::Value item;
        item[0] = get<0>(startPoint);
        item[1] = get<1>(startPoint);
        item[2] = 1;
        arrayObj.append(item);
        for (int i = 0; i < path.size(); i++)
        {
            Json::Value item;
            item[0] = get<0>(path[i]);
            item[1] = get<1>(path[i]);
            item[2] = 3;
            arrayObj.append(item);
        }
        item[0] = get<0>(destinationPoint);
        item[1] = get<1>(destinationPoint);
        item[2] = 2;
        arrayObj.append(item);
        for (const auto &obstacle : obstacles) {
            Json::Value item;
            item[0] = get<0>(obstacle);
            item[1] = get<1>(obstacle);
            item[2] = 0;
            arrayObj.append(item);
        }
        root["data"] = arrayObj;

        ofstream out(filename);
        out << root.toStyledString() << endl;
        out.close();
    }

};


#endif //ASTARPATHPLANNING_UTILS_H