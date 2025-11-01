#include "rapidjson/document.h"
#include "rapidjson/istreamwrapper.h"
#include <bits/stdc++.h>

using namespace std;
using namespace rapidjson;

void get_params() {
    Document d;
    ifstream in("params.json");
    IStreamWrapper isw(in);
    d.ParseStream(isw);

    SEED_RANDOM = d["seed_random"].GetBool();
    SEED = d["seed"].GetInt();
    FILENAME = d["filename"].GetString();
    WIDTH = d["width"].GetInt();
    HEIGHT = d["height"].GetInt();
    VARIETY = d["variety"].GetInt();
    NUM = d["num"].GetInt();
    auto r = d["r"].GetArray();
    for (int i = 0; i < r.Size(); ++i) { R[i] = r[i].GetInt(); }
    auto g = d["g"].GetArray();
    for (int i = 0; i < g.Size(); ++i) { G[i] = g[i].GetInt(); }
    auto b = d["b"].GetArray();
    for (int i = 0; i < b.Size(); ++i) { B[i] = b[i].GetInt(); }
    RANDOM_CENTER_XY = d["random_center_xy"].GetBool();
    CENTER_X = d["center_x"].GetInt();
    CENTER_Y = d["center_y"].GetInt();
    RANDOM_CENTER_COL = d["random_center_col"].GetBool();
    CENTER_R = d["center_r"].GetInt();
    CENTER_G = d["center_g"].GetInt();
    CENTER_B = d["center_b"].GetInt();
    DISRUPTION = d["disruption"].GetDouble();
    R_INCREASE_PROBABILITY = d["r_increase_probability"].GetDouble();
    G_INCREASE_PROBABILITY = d["g_increase_probability"].GetDouble();
    B_INCREASE_PROBABILITY = d["b_increase_probability"].GetDouble();
    R_DECREASE_PROBABILITY = d["r_decrease_probability"].GetDouble();
    G_DECREASE_PROBABILITY = d["g_decrease_probability"].GetDouble();
    B_DECREASE_PROBABILITY = d["b_decrease_probability"].GetDouble();
}
