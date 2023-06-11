/* Given a 2-D matrix representing an image, a location of a pixel in the screen and a color C, 
replace the color of the given pixel and all adjacent same colored pixels with C.*/

#include <iostream>
#include <vector>

using namespace std;

struct Color {
    float r, g, b;
};

struct Position {
    int x, y;
};

void printColor(Color& color)
{
    cout << "(" << color.r << "," << color.g << "," << color.b << ")";
}

void replaceColor(Position position, vector<vector<Color>>& image, Color newColor)
{
    int width = image[0].size();
    int height = image.size();

    Color currentColor = image[position.y][position.x];

    for (int x=-1; x<=1; x++)
    {
        for (int y=-1; y<=1; y++)
        {
            bool isInMatrix = (position.x + x >= 0) && (position.x + x < width) && (position.y + y >= 0) && (position.y + y < height);
            if (isInMatrix)
            {
                bool sameColor = (image[position.y + y][position.x + x].r == currentColor.r) && (image[position.y + y][position.x + x].g == currentColor.g) && (image[position.y + y][position.x + x].b == currentColor.b);
                if (sameColor)
                {
                    image[position.y + y][position.x + x].r = newColor.r;
                    image[position.y + y][position.x + x].g = newColor.g;
                    image[position.y + y][position.x + x].b = newColor.b;
                }
            }
        }
    }
}

void printImage(vector<vector<Color>>& image)
{
    int width = image[0].size();
    int height = image.size();

    for (int y=0; y<height; y++)
    {
        cout << "| " ;
        for (int x=0; x<width; x++)
        {
            printColor(image[y][x]);
            cout << " ";
        }
        cout << " |" << endl ;
    }
}

int main(int argc, char *argv[])
{
    Color blue ;
    blue.r = blue.g = 0;
    blue.b = 1;
    vector<vector<Color>> image(3, vector<Color>(5, blue));

    Color red ;
    red.b = red.g = 0;
    red.r = 1;

    Color green;
    green.r = green.b = 0;
    green.g = 1;

    image[0][1] = image[0][2] = image[0][3] = image[1][2] = red;

    printImage(image);
    cout << "=== New Image ===" << endl;

    Position toReplace ;
    toReplace.x = 2;
    toReplace.y = 1;

    replaceColor(toReplace, image, green);
    printImage(image);
}