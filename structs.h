#include <bits/stdc++.h>
#include <lodepng/lodepng.h>
using namespace std;

struct Pixel {
    unsigned char r, g, b, a;

    bool operator<(Pixel o) {
        if (r + g + b == o.r + o.g + o.b) {
            vector<int> A = {r, g, b};
            vector<int> B = {o.r, o.g, o.b};
            return A < B;
        }
        return r + g + b < o.r + o.g + o.b;
    }
};

struct Image {
    unsigned int width, height;
    vector<vector<Pixel>> p;

    Image(unsigned _width, unsigned _height, const vector<unsigned char>& raw) {
        if (raw.size() != _width * _height * 4) {
            cerr << "Failed to create image of size " << _width << " x " << _height << ": " << endl;
            cerr << "Provided array with length of " << raw.size() << " elements. " << endl;
            cerr << "Expected array with length of " << _width * _height * 4 << " elements. " << endl;
            exit(0);
        }
        width = _width;
        height = _height;
        p.assign(height, vector<Pixel>(width));
        for (int i = 0; i < raw.size(); i += 4) {
            p[(i / 4) / width][(i / 4) % width] = Pixel(raw[i], raw[i + 1], raw[i + 2], raw[i + 3]);
        }
    }

    void toRaw(unsigned &_width, unsigned &_height, vector<unsigned char> &raw) {
        _width = width;
        _height = height;
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                raw.push_back(p[i][j].r);
                raw.push_back(p[i][j].g);
                raw.push_back(p[i][j].b);
                raw.push_back(p[i][j].a);
            }
        }
    }
};
