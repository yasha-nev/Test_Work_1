#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int Compaire(float b_l, float b_w, float b_h, float h_l, float h_w);


int main(int argc, char *argv[])
{
    if (argc <=2){
        cout << "error" << endl;
        return 0;
    }
    fstream out(argv[1], ios::in);
    fstream in(argv[2], ios::out);

    if (!out && !in){
        cout << "files didnt open" << endl;
    }
    float brick_length, brick_width, brick_height;
    float hole_length, hole_width;


    cout << "Enter brick length, width, height" << endl;
    cin >> brick_length >> brick_width >> brick_height;

    out >> hole_length;
    out >> hole_width;

    cout << "Hole length = " << hole_length << endl;
    cout << "Hole width = " << hole_width << endl;

    int result = Compaire(brick_length, brick_width, brick_height, hole_length, hole_width);

    if (result == 1){
        cout << "Brick will enter" << endl;
        in << "yes";
    }
    else{
        cout << "Brick wont enter" << endl;
        in << "No";
    }

    out.close();
    in.close();

    return 0;
}


int Compaire(float b_l, float b_w, float b_h, float h_l, float h_w){

    if ((b_l <= h_l && b_w <= h_w) || (b_w <= h_l && b_l <= h_w)){
        return 1;
    }
    else if ((b_l <= h_l && b_h <= h_w) || (b_h <= h_l && b_l <= h_w)){
        return 1;
    }
    else if ((b_w <= h_l && b_h <= h_w) || (b_h <= h_l && b_w <= h_w)){
        return 1;
    }
    else{
        return 0;
    }

}

