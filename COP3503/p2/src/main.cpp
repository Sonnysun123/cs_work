#include "path.h"
#include "task.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void Close2Files(ifstream& inputFile1, ofstream& outputFile);
void Close3Files(ifstream& topLayer, ifstream& bottomLayer, ofstream& outputFile);
void Close4Files(ifstream& inputFile1, ifstream& inputFile2, ifstream& inputFile3, ofstream& outputFile);
void Close4Files(ifstream& inputFile1, ofstream& outputFile1, ofstream& outputFile2, ofstream& outputFile3);
void Close5Files(ifstream& inputFile1, ifstream& inputFile2, ifstream& inputFile3, ifstream& inputFile4, ofstream& outputFile);
void Load2Streams(string& inputFile1Path, string& outputPath, ifstream& inputFile1, ofstream& outputFile);
void Load3Streams(string& topLayerPath, string& bottomLayerPath, string& outputPath, ifstream& topLayer, ifstream& bottomLayer, ofstream& outputFile);
void Load4Streams(string& inputFile1Path, string& inputFile2Path, string& inputFile3Path, string& outputPath, ifstream& inputFile1, ifstream& inputFile2, ifstream& inputFile3, ofstream& outputFile);
void Load4Streams(string& inputFile1Path, string& outputFile1Path, string& outputFile2Path, string& outputFile3Path, ifstream& inputFile1, ofstream& outputFile1, ofstream& outputFile2, ofstream& outputFile3);
void Load5Streams(string& inputFile1Path, string& inputFile2Path, string& inputFile3Path, string& inputFile4Path, string& outputPath, ifstream& inputFile1, ifstream& inputFile2, ifstream& inputFile3, ifstream& inputFile4, ofstream& outputFile);
string CheckIdenticalImage(ifstream& example, ifstream& newFile);
void CheckTask(string& examplePath, string& outputPath, ifstream& exampleFile, ifstream& newFile);

int main() {
    Path path;
    string topLayerPath, bottomLayerPath, examplePath, outputPath;
    ifstream topLayer, bottomLayer, exampleFile, newFile;
    ofstream outputFile;
    /*===========================Task1================================*/
    topLayerPath = path.task1Path[0];
    bottomLayerPath = path.task1Path[1];
    outputPath = path.task1Path[2];
    examplePath = path.examplePath[0];
    Load3Streams(topLayerPath, bottomLayerPath, outputPath, topLayer, bottomLayer, outputFile);
    Task1(topLayer, bottomLayer, outputFile);
    Close3Files(topLayer, bottomLayer, outputFile);
    CheckTask(examplePath, outputPath, exampleFile, newFile);

    /*==============================Task2================================*/
    topLayerPath = path.task2Path[0];
    bottomLayerPath = path.task2Path[1];
    outputPath = path.task2Path[2];
    examplePath = path.examplePath[1];
    Load3Streams(topLayerPath, bottomLayerPath, outputPath, topLayer, bottomLayer, outputFile);
    Task2(topLayer, bottomLayer, outputFile);
    Close3Files(topLayer, bottomLayer, outputFile);
    CheckTask(examplePath, outputPath, exampleFile, newFile);
    /*============================Task 3===================================*/
    string inputFile1Path = path.task3Path[0];
    string inputFile2Path = path.task3Path[1];
    string inputFile3Path = path.task3Path[2];
    outputPath = path.task3Path[3];
    examplePath = path.examplePath[2];
    ifstream inputFile1;
    ifstream inputFile2;
    ifstream inputFile3;
    Load4Streams(inputFile1Path, inputFile2Path, inputFile3Path, outputPath, inputFile1, inputFile2, inputFile3, outputFile);
    Task3(inputFile1, inputFile2, inputFile3,outputFile);
    Close4Files(inputFile1, inputFile2, inputFile3, outputFile);
    CheckTask(examplePath, outputPath, exampleFile,newFile);
    /*===========================Task 4=========================*/
    inputFile1Path = path.task4Path[0];
    inputFile2Path = path.task4Path[1];
    inputFile3Path = path.task4Path[2];
    outputPath = path.task4Path[3];
    examplePath = path.examplePath[3];
    Load4Streams(inputFile1Path, inputFile2Path, inputFile3Path, outputPath, inputFile1, inputFile2, inputFile3, outputFile);
    Task4(inputFile1, inputFile2, inputFile3,outputFile);
    Close4Files(inputFile1, inputFile2, inputFile3, outputFile);
    CheckTask(examplePath, outputPath, exampleFile,newFile);
    /*===========================Task 5=============================*/
    topLayerPath = path.task5Path[0];
    bottomLayerPath = path.task5Path[1];
    outputPath = path.task5Path[2];
    examplePath = path.examplePath[4];
    Load3Streams(topLayerPath, bottomLayerPath, outputPath, topLayer, bottomLayer, outputFile);
    Task5(topLayer, bottomLayer, outputFile);
    Close3Files(topLayer, bottomLayer, outputFile);
    CheckTask(examplePath, outputPath, exampleFile, newFile);
    /*=======================Task 6===============================*/
    inputFile1Path = path.task6Path[0];
    outputPath = path.task6Path[1];
    examplePath = path.examplePath[5];
    Load2Streams(inputFile1Path, outputPath, inputFile1, outputFile);
    Task6(inputFile1, outputFile);
    Close2Files(inputFile1, outputFile);
    CheckTask(examplePath, outputPath, exampleFile, newFile);
    /*========================Task 7=========================*/
    inputFile1Path = path.task7Path[0];
    outputPath = path.task7Path[1];
    examplePath = path.examplePath[6];
    Load2Streams(inputFile1Path, outputPath, inputFile1, outputFile);
    Task7(inputFile1, outputFile);
    Close2Files(inputFile1, outputFile);
    CheckTask(examplePath, outputPath, exampleFile, newFile);
    /*====================Task 8============================*/
    inputFile1Path = path.task8Path[0];
    string outputFile1Path = path.task8Path[1];
    string outputFile2Path = path.task8Path[2];
    string outputFile3Path = path.task8Path[3];
    string examplePath1 = path.examplePath[7];
    string examplePath2 = path.examplePath[8];
    string examplePath3 = path.examplePath[9];
    ofstream outputFile1;
    ofstream outputFile2;
    ofstream outputFile3;
    Load4Streams(inputFile1Path, outputFile1Path, outputFile2Path, outputFile3Path, inputFile1, outputFile1, outputFile2, outputFile3);
    Task8(inputFile1, outputFile1, outputFile2, outputFile3);
    Close4Files(inputFile1, outputFile1, outputFile2, outputFile3);
    CheckTask(examplePath1, outputFile1Path, exampleFile, newFile);
    CheckTask(examplePath2, outputFile2Path, exampleFile, newFile);
    CheckTask(examplePath3, outputFile3Path, exampleFile, newFile);
    /*=============================Task 9================================*/
    inputFile1Path = path.task9Path[0];
    inputFile2Path = path.task9Path[1];
    inputFile3Path = path.task9Path[2];
    outputPath = path.task9Path[3];
    examplePath = path.examplePath[10];
    Load4Streams(inputFile1Path, inputFile2Path, inputFile3Path, outputPath, inputFile1, inputFile2, inputFile3, outputFile);
    Task9(inputFile1, inputFile2, inputFile3, outputFile);
    Close4Files(inputFile1, inputFile2, inputFile3, outputFile);
    CheckTask(examplePath, outputPath, exampleFile, newFile);
    /*===========================Task 10===========================*/
    inputFile1Path = path.task10Path[0];
    outputPath = path.task10Path[1];
    examplePath = path.examplePath[11];
    Load2Streams(inputFile1Path, outputPath, inputFile1, outputFile);
    Task10(inputFile1, outputFile);
    Close2Files(inputFile1, outputFile);
    CheckTask(examplePath, outputPath, exampleFile, newFile);
    /*==========================Task Extra Credit============================*/
    inputFile1Path = path.taskECPath[0];
    inputFile2Path = path.taskECPath[1];
    inputFile3Path = path.taskECPath[2];
    string inputFile4Path = path.taskECPath[3];
    outputPath = path.taskECPath[4];
    examplePath = path.examplePath[12];
    ifstream inputFile4;
    Load5Streams(inputFile1Path, inputFile2Path, inputFile3Path, inputFile4Path, outputPath, inputFile1, inputFile2, inputFile3, inputFile4, outputFile);
    TaskEC(inputFile1, inputFile2, inputFile3, inputFile4, outputFile);
    Close5Files(inputFile1, inputFile2, inputFile3, inputFile4, outputFile);
    CheckTask(examplePath, outputPath, exampleFile, newFile);
}   


void Load2Streams(string& inputFile1Path, string& outputPath, ifstream& inputFile1, ofstream& outputFile) {
    inputFile1.open(inputFile1Path, ios::binary);
    outputFile.open(outputPath, ios::binary);
    if (!inputFile1.is_open())
        cout << "input file is not opened" << endl;
    if (!outputFile.is_open())
        cout << "output file is not opened" << endl;
}

void Load3Streams(string& topLayerPath, string& bottomLayerPath, string& outputPath, ifstream& topLayer, ifstream& bottomLayer, ofstream& outputFile) {
    topLayer.open(topLayerPath, ios::binary);
    bottomLayer.open(bottomLayerPath, ios::binary);
    outputFile.open(outputPath, ios::binary);
    if (!topLayer.is_open() || !bottomLayer.is_open() || !outputFile.is_open() ) {
        if (!topLayer.is_open())
            cout << "error opening top layer" << endl;
        if (!bottomLayer.is_open())
            cout << "error opening bottom layer" << endl;
        if (!outputFile.is_open())
            cout << "error opening output file" << endl;
        cout << "Error opening file" << endl;
        exit(1);
    }
}
void Load4Streams(string& inputFile1Path, string& inputFile2Path, string& inputFile3Path, string& outputPath, ifstream& inputFile1, ifstream& inputFile2, ifstream& inputFile3, ofstream& outputFile) {
    inputFile1.open(inputFile1Path, ios::binary);
    inputFile2.open(inputFile2Path, ios::binary);
    inputFile3.open(inputFile3Path, ios::binary);
    outputFile.open(outputPath, ios::binary);
    if (!inputFile1.is_open() || !inputFile2.is_open() || !inputFile3.is_open() || !outputFile.is_open()) {
        if (!inputFile1.is_open())
            cout << "input file 1 error" << endl;
        if (!inputFile2.is_open())
            cout << "input file 2 error" << endl;
        if (!inputFile3.is_open())
            cout << "input file 3 error" << endl;
        if (!outputFile.is_open())
            cout << "output file error" << endl;
        cout << "Error opening file" << endl;
        exit(1);
    }

}   
void Load4Streams(string& inputFile1Path, string& outputFile1Path, string& outputFile2Path, string& outputFile3Path, ifstream& inputFile1, ofstream& outputFile1, ofstream& outputFile2, ofstream& outputFile3) {
    inputFile1.open(inputFile1Path,ios::binary);
    outputFile1.open(outputFile1Path,ios::binary);
    outputFile2.open(outputFile2Path, ios::binary);
    outputFile3.open(outputFile3Path, ios::binary);
    if (!inputFile1.is_open() || !outputFile1.is_open() || !outputFile2.is_open() || !outputFile3.is_open()) {
        if (!inputFile1.is_open())
            cout << "input file 1 error" << endl;
        if (!outputFile1.is_open())
            cout << "output file 1 error" << endl;
        if (!outputFile2.is_open())
            cout << "output file 2 error" << endl;
        if (!outputFile3.is_open())
            cout << "output file 3 error" << endl;
        cout << "Error opening file" << endl;
        exit(1);
    }
}
void Load5Streams(string& inputFile1Path, string& inputFile2Path, string& inputFile3Path, string& inputFile4Path, string& outputPath, ifstream& inputFile1, ifstream& inputFile2, ifstream& inputFile3, ifstream& inputFile4, ofstream& outputFile) {
 inputFile1.open(inputFile1Path, ios::binary);
    inputFile2.open(inputFile2Path, ios::binary);
    inputFile3.open(inputFile3Path, ios::binary);
    inputFile4.open(inputFile4Path, ios::binary);
    outputFile.open(outputPath, ios::binary);

    if (!inputFile1.is_open() || !inputFile2.is_open() || !inputFile3.is_open() || !inputFile4.is_open() || !outputFile.is_open()) {
        if (!inputFile1.is_open())
            cout << "input file 1 error" << endl;
        if (!inputFile2.is_open())
            cout << "input file 2 error" << endl;
        if (!inputFile3.is_open())
            cout << "input file 3 error" << endl;
        if (!inputFile4.is_open())
            cout << "input file 4 error" << endl;
        if (!outputFile.is_open())
            cout << "output file error" << endl;
        cout << "Error opening file" << endl;
        exit(1);
    }
}
void Close2Files(ifstream& inputFile1, ofstream& outputFile) {
    inputFile1.close();
    outputFile.close();
}
void Close3Files(ifstream& topLayer, ifstream& bottomLayer, ofstream& outputFile) {
    topLayer.close();
    bottomLayer.close();
    outputFile.close();
}
void Close4Files(ifstream& inputFile1, ifstream& inputFile2, ifstream& inputFile3, ofstream& outputFile) {
    inputFile1.close();
    inputFile2.close();
    inputFile3.close();
    outputFile.close();
}
void Close4Files(ifstream& inputFile1, ofstream& outputFile1, ofstream& outputFile2, ofstream& outputFile3) {
    inputFile1.close();
    outputFile1.close();
    outputFile2.close();
    outputFile3.close();
}
void Close5Files(ifstream& inputFile1, ifstream& inputFile2, ifstream& inputFile3, ifstream& inputFile4, ofstream& outputFile) {
    inputFile1.close();
    inputFile2.close();
    inputFile3.close();
    inputFile4.close();
    outputFile.close();
}
string CheckIdenticalImage(ifstream& example, ifstream& newFile) {
   
    if (!example.is_open() || !newFile.is_open())
        return "Can't open files";

    example.seekg(0, ios::end);
    newFile.seekg(0, ios::end);
    streampos size1 = example.tellg();
    streampos size2 = newFile.tellg();

    if (size1 != size2)
        return "Not the same size";

    example.seekg(0, ios::beg);
    newFile.seekg(0, ios::beg);

    const size_t bufferSize = 4096;
    std::vector<char> buffer1(bufferSize);
    std::vector<char> buffer2(bufferSize);

    while (example.good() && newFile.good()) {
        example.read(buffer1.data(), bufferSize);
        newFile.read(buffer2.data(), bufferSize);

        if (example.gcount() != newFile.gcount()) 
            return "Byte not read the same";
        
        if (!std::equal(buffer1.begin(), buffer1.begin() + example.gcount(), buffer2.begin())) {
            return "Buffer not the same";
        }
    }

    return "Files are the same";
}
void CheckTask(string& examplePath, string& outputPath, ifstream& exampleFile, ifstream& newFile) {
    exampleFile.open(examplePath);
    newFile.open(outputPath);
    cout << CheckIdenticalImage(exampleFile, newFile) << endl;
    exampleFile.close();
    newFile.close();
}   
