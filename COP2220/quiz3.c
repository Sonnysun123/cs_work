#include <stdbool.h>
#include <stdio.h>

void AskUserInput(float* GPA, int* testScore) { //Instructs user to enter GPA and test score
    printf("Enter your GPA: "); //Asks GPA
    scanf("%f", GPA); //Reads GPA
    printf("Enter your test score: "); //Asks test score
    scanf("%d", testScore); //Reads test score
}
bool CheckAdmission(float GPA, int testScore) { //Determine if the student is qualified for admission
    if (GPA >= 3.0f && testScore >= 60) //if GPA is 3.0 or higher and test score is 60 or higher
        return true;
    if (GPA < 3.0f && testScore >= 80) //if GPA is less than 3.0 and test score is 80 or higher
        return true;
    return false; //return false if non of the criterias are meet
    
}
int main(void) {
    float GPA = 0.0f;
    int testScore = 0;
    AskUserInput(&GPA, &testScore); //pass by pointer
    bool result = CheckAdmission(GPA, testScore); //checks if student is qualified
    if (result) //If student is qualified
        printf("Accept"); 
    else //If student is not qualified
        printf("Reject");
}