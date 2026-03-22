#include <string>
#include <vector>
using namespace std;

struct Path {
    vector<string> examplePath = {"examples/EXAMPLE_part1.tga","examples/EXAMPLE_part2.tga","examples/EXAMPLE_part3.tga","examples/EXAMPLE_part4.tga","examples/EXAMPLE_part5.tga","examples/EXAMPLE_part6.tga","examples/EXAMPLE_part7.tga","examples/EXAMPLE_part8_r.tga","examples/EXAMPLE_part8_g.tga", "examples/EXAMPLE_part8_b.tga","examples/EXAMPLE_part9.tga","examples/EXAMPLE_part10.tga","examples/EXAMPLE_extracredit.tga"};
    vector<string> task1Path = {"input/layer1.tga", "input/pattern1.tga", "output/part1.tga"};
    vector<string> task2Path = {"input/layer2.tga", "input/car.tga", "output/part2.tga"};
    vector<string> task3Path = {"input/layer1.tga", "input/pattern2.tga", "input/text.tga","output/part3.tga"};
    vector<string> task4Path = {"input/layer2.tga", "input/circles.tga", "input/pattern2.tga", "output/part4.tga"};
    vector<string> task5Path = {"input/layer1.tga", "input/pattern1.tga", "output/part5.tga"};
    vector<string> task6Path = {"input/car.tga", "output/part6.tga"};
    vector<string> task7Path = {"input/car.tga", "output/part7.tga"};
    vector<string> task8Path = {"input/car.tga", "output/part8_r.tga", "output/part8_g.tga", "output/part8_b.tga"};
    vector<string> task9Path = {"input/layer_red.tga", "input/layer_green.tga", "input/layer_blue.tga", "output/part9.tga"};
    vector<string> task10Path = {"input/text2.tga", "output/part10.tga"};
    vector<string> taskECPath = {"input/car.tga", "input/circles.tga", "input/pattern1.tga", "input/text.tga", "output/extracredit.tga"};
};  