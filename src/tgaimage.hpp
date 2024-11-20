// include guard
#pragma once

#include <fstream> // library for reading/writing files

/**
 * The header information for a TGA file.
 */
#pragma pack(push, 1) // ensure no padding between member variables
struct TGA_Header {
    char idlength;
    char colormaptype;
    char datatypecode;
    short colormaporigin;
    short colormaplength;
    char colormapdepth;
    short x_origin;
    short y_origin;
    short width;
    short height;
    char bitsperpixel;
    char imagedescriptor;
};
#pragma pack(pop)

/**
 * A class representing colors in TGA images.
 */
struct TGAColor {

    // union here means that all members in the scope
    // will share the same memory location
    union {
        struct {
            unsigned char b, g, r, a; // chars for each color channel
        };
        unsigned char raw[4]; // array of 4 chars
        unsigned int val;     // stores the color as one 32-bit integer
    };

    /**
     * Bytes per pixel.
     * 1 bpp => 8-bit grayscale
     * 3 bpp => 24-bit RGB
     * 4 bpp => 32-bit RGBA
     */
    int bytespp;

    // Constructors

    TGAColor() : val(0), bytespp(1) {}

    TGAColor(unsigned char R, unsigned char G, unsigned char B, unsigned char A)
        : b(B), g(G), r(R), a(A), bytespp(4) {}

    TGAColor(int v, int bpp) : val(v), bytespp(bpp) {}

    TGAColor(const TGAColor &c) : val(c.val), bytespp(c.bytespp) {}

    TGAColor(const unsigned char *p, int bpp) : val(0), bytespp(bpp) {
        for (int i = 0; i < bpp; i++) {
            raw[i] = p[i];
        }
    }

    /**
     * Assignment operator.
     */
    TGAColor &operator=(const TGAColor &c) {
        if (this != &c) {
            bytespp = c.bytespp;
            val     = c.val;
        }
        return *this;
    }
};

/**
 * A class representing TGA images.
 */
class TGAImage {
protected:
    unsigned char *data; // the actual img data
    int width;
    int height;
    /**
     * Bytes per pixel.
     * 1 bpp => 8-bit grayscale
     * 3 bpp => 24-bit RGB
     * 4 bpp => 32-bit RGBA
     */
    int bytespp;

    /**
     * Loads the RLE compressed data from the given input stream.
     * @param in the given input stream
     * @return true if the compressed data was read, false otherwise
     */
    bool load_rle_data(std::ifstream &in);

    bool unload_rle_data(std::ofstream &out);

public:
    /**
     * Enum representing the format of the TGA image.
     */
    enum Format { GRAYSCALE = 1, RGB = 3, RGBA = 4 };

    TGAImage();
    TGAImage(int w, int h, int bpp);
    TGAImage(const TGAImage &img);

    /**
     * Reads the given TGA file and writes its data to this TGAImage.
     * Any previous data will be overwritten!!
     * @param filename the given TGA file
     * @return true if the file was read, false otherwise
     */
    bool read_tga_file(const char *filename);
    /**
     * Writes the data of this TGAImage to a TGA file.
     * @param filename the name of the file to write to
     * @param rle whether to use RLE compression
     * @return true if the file was written, false otherwise
     */
    bool write_tga_file(const char *filename, bool rle = true);
    bool flip_horizontally();
    bool flip_vertically();
    bool scale(int w, int h);
    // Gets pixel color
    TGAColor get(int x, int y);
    // Sets pixel color
    bool set(int x, int y, TGAColor c);
    ~TGAImage();
    TGAImage &operator=(const TGAImage &img);
    int get_width();
    int get_height();
    int get_bytespp();
    // returns the image data
    unsigned char *buffer();
    // erases image data
    void clear();
};
