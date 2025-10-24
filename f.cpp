#include "structs.h"
#include "params.h"

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

deque<tuple<int, int, unsigned char, unsigned char, unsigned char>> q;
vector<vector<int>> dir({{-1, 0},
                         {0,  -1},
                         {1,  0},
                         {0,  1}});

void bfs(Image &image) {
    while (!q.empty()) {
        swap(q[0], q[rnd() % q.size()]);
        auto x = q.front();
        q.pop_front();
        int i = get<0>(x);
        int j = get<1>(x);
        if (image.p[i][j].a == 0) {
            image.p[i][j].r = get<2>(x);
            image.p[i][j].g = get<3>(x);
            image.p[i][j].b = get<4>(x);
            image.p[i][j].a = 255;
        }
        vector<pair<int, int>> c;
        for (auto e: dir) {
            int i1 = i + e[0];
            int j1 = j + e[1];
            if (0 <= i1 && i1 < HEIGHT && 0 <= j1 && j1 < WIDTH && image.p[i1][j1].a == 0) {
                c.emplace_back(i1, j1);
            }
        }
        for (auto &k: c) {
            int i1 = k.first;
            int j1 = k.second;
            int k1 = signed(rnd() % VARIETY);
            int k2 = signed(rnd() % VARIETY);
            int k3 = signed(rnd() % VARIETY);
            if (0 <= i1 && i1 < HEIGHT && 0 <= j && j < WIDTH && image.p[i1][j1].a == 0) {
                int r, g, b;
                if (!BLACK_AND_WHITE) {
                    r = signed((rnd() % 3) - 1) * k1 + image.p[i][j].r;
                    g = signed((rnd() % 3) - 1) * k2 + image.p[i][j].g;
                    b = signed((rnd() % 3) - 1) * k3 + image.p[i][j].b;
                } else {
                    int rd = signed(rnd() % 3) - 1;
                    r = rd * k1 + image.p[i][j].r;
                    g = rd * k1 + image.p[i][j].g;
                    b = rd * k1 + image.p[i][j].b;
                }
                r = max(int(R[0]), min(r, int(R[1])));
                g = max(int(G[0]), min(g, int(G[1])));
                b = max(int(B[0]), min(b, int(B[1])));
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
    Image image(WIDTH, HEIGHT, vector<unsigned char>(WIDTH * HEIGHT * 4, 0));

    for (int i = 0; i < NUM; ++i) {
        int start_x = CENTER_X, start_y = CENTER_Y;
        if (RANDOM_CENTER_XY) {
            start_x = signed(rnd() % HEIGHT), start_y = signed(rnd() % WIDTH);
        }

        if (!BLACK_AND_WHITE) {
            if (RANDOM_CENTER_COL) {
                q.emplace_back(start_x, start_y, rnd(), rnd(), rnd());
            } else {
                q.emplace_back(start_x, start_y, CENTER_R, CENTER_G, CENTER_B);
            }
        } else {
            unsigned char c = CENTER_RGB_BW;
            if (RANDOM_CENTER_COL) {
                c = rnd();
            }
            q.emplace_back(start_x, start_y, c, c, c);
        }
    }

    bfs(image);
    return image;
}