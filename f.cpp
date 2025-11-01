#include "structs.h"
#include "params.h"

mt19937 rnd(0);

deque<tuple<int, int, unsigned char, unsigned char, unsigned char>> q;
vector<vector<int>> directions({{-1, 0},
                                {0,  -1},
                                {1,  0},
                                {0,  1},
                                {-1, -1},
                                {-1, 1},
                                {1,  -1},
                                {1,  1}});

void bfs(Image &image) {
    while (!q.empty()) {
        swap(q[0], q[rnd() % q.size()]);
        auto x = q.front();
        q.pop_front();
        int i = get<0>(x);
        int j = get<1>(x);
        vector<pair<int, int>> c;
        for (auto e: directions) {
            int i1 = i + e[0];
            int j1 = j + e[1];
            if (0 <= i1 && i1 < HEIGHT && 0 <= j1 && j1 < WIDTH && image.p[i1][j1].a == 0) {
                c.emplace_back(i1, j1);
            }
        }
        auto calc_probability = [&](double prob) { return (rnd() < prob * UINT32_MAX); };
        for (auto &k: c) {
            int i1 = k.first;
            int j1 = k.second;
            int kr = signed(rnd() % VARIETY);
            int kg = signed(rnd() % VARIETY);
            int kb = signed(rnd() % VARIETY);
            int delta_r = 0, delta_g = 0, delta_b = 0;
            delta_r += (calc_probability(R_INCREASE_PROBABILITY)) * kr;
            delta_g += (calc_probability(G_INCREASE_PROBABILITY)) * kg;
            delta_b += (calc_probability(B_INCREASE_PROBABILITY)) * kb;
            delta_r -= (calc_probability(R_DECREASE_PROBABILITY)) * kr;
            delta_g -= (calc_probability(G_DECREASE_PROBABILITY)) * kg;
            delta_b -= (calc_probability(B_DECREASE_PROBABILITY)) * kb;
            if (0 <= i1 && i1 < HEIGHT && 0 <= j && j < WIDTH && image.p[i1][j1].a == 0) {
                int r = delta_r + int(image.p[i][j].r);
                int g = delta_g + int(image.p[i][j].g);
                int b = delta_b + int(image.p[i][j].b);
                if (calc_probability(DISRUPTION)) {
                    r = rnd(), g = rnd(), b = rnd();
                }
                r = max(R[0], min(r, R[1]));
                g = max(G[0], min(g, G[1]));
                b = max(B[0], min(b, B[1]));
                image.p[i1][j1].r = r;
                image.p[i1][j1].g = g;
                image.p[i1][j1].b = b;
                image.p[i1][j1].a = 255;
                q.emplace_back(i1, j1, r, g, b);
            }
        }
    }
}

Image img() {
    unsigned int seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    if (SEED_RANDOM) { seed = SEED; }
    rnd.seed(seed);
    cout << seed << "\n";
    Image image(WIDTH, HEIGHT, vector<unsigned char>(WIDTH * HEIGHT * 4, 0));
    for (int i = 0; i < NUM; ++i) {
        int start_x = CENTER_X, start_y = CENTER_Y;
        if (RANDOM_CENTER_XY) {
            start_x = signed(rnd() % HEIGHT), start_y = signed(rnd() % WIDTH);
        }

        int r = CENTER_R;
        int g = CENTER_G;
        int b = CENTER_B;
        if (RANDOM_CENTER_COL) {
            r = max(R[0], min(int((unsigned char) rnd()), R[1]));
            g = max(G[0], min(int((unsigned char) rnd()), G[1]));
            b = max(B[0], min(int((unsigned char) rnd()), B[1]));
        }
        r = max(R[0], min(r, R[1]));
        g = max(G[0], min(g, G[1]));
        b = max(B[0], min(b, B[1]));
        image.p[start_x][start_y].r = r;
        image.p[start_x][start_y].g = g;
        image.p[start_x][start_y].b = b;
        image.p[start_x][start_y].a = 255;
        q.emplace_back(start_x, start_y, r, g, b);
    }

    bfs(image);
    return image;
}