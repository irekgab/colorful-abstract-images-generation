#include "f.cpp"
#include "json_parse.cpp"

using namespace std;

void encodeOneStep(const string &filename, Image image) {
    vector<unsigned char> raw;
    unsigned w, h;
    image.toRaw(w, h, raw);
    unsigned error = lodepng::encode(filename, raw, WIDTH, HEIGHT);
    if (error) {
        cerr << "encoder error " << error << ": " << lodepng_error_text(error) << endl;
        exit(0);
    }
}

int main(int argc, char *argv[]) {
    const string filename = argc > 1 ? argv[1] : "test.png";
    get_params();
    Image res = img();
    encodeOneStep("result.png", res);
    return 0;
}