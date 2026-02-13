// compile: g++ -std=c++14 -o pointers pointers.cpp
#include <iostream>
#include <string>

typedef struct Student {
    int id;
    char *f_name;
    char *l_name;
    int n_assignments;
    double *grades;
} Student;

int promptInt(std::string message, int min, int max);
double promptDouble(std::string message, double min, double max);
void calculateStudentAverage(void *object, double *avg);

int main(int argc, char **argv)
{
    Student student;
    double average;

    // Sequence of user input -> store in fields of `student`
    student.id = promptInt("Please enter the student's id number: ", 0, 999999999);

    //get first name
    std::cout << "Please enter the student's first name: ";
    std::cin.getline(student.f_name,128);

    //get last name
    std::cout << "Please enter the student's last name: ";
    std::cin.getline(student.l_name,128);

    //number of assignments
    student.n_assignments = promptInt("Please enter how many assignments were graded: ", 1, 134217727);

    //allocate memory dynamically for grades
    student.grades = new double[student.n_assignments];

    std::cout << std::endl;

    //get grades
    for(int i=0; i<student.n_assignments;i++){
        student.grades[i] = promptDouble("Please enter grade for assignment" + std::to_string(i) + ": ", 0.0, 1000.0);
    }

    std::cout << std::endl;







    

    // Call `CalculateStudentAverage(???, ???)`
    calculateStudentAverage(&student,&average);
    double round = (int)(average*10+0.5)/10.0;

    // Output `average`
    std::cout << "Student: " << student.f_name << " " << student.l_name 
    << " [" << student.id << "]" << std::endl;

    std::cout << "  Average grade: " << round << std::endl;

    delete[] student.grades;

    return 0;
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid int
   max: maximum value to accept as a valid int
*/
int promptInt(std::string message, int min, int max)
{
    std::string tempstr;
    // Code to prompt user for an int
    while(true){
        std::cout << message;
        std::getline(std::cin,tempstr);

        try{
            size_t numconv;
            int value = std::stoi(tempstr, &numconv);//convert to int, track number of items converted
            
            if(numconv != tempstr.length())
            throw std::invalid_argument("non number input");

            if(value < min || value > max)
            throw std::out_of_range("out of range");

            return value;
        }
        catch(...){
            std::cout << "Sorry, I cannot understand your answer" << std::endl;
        }
    }

}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid double
   max: maximum value to accept as a valid double
*/
double promptDouble(std::string message, double min, double max)
{
    std::string buildstr;
    // Code to prompt user for a double

    while(true){
        std::cout << message;
        std::getline(std::cin, buildstr);

        try{
            size_t nconvert;
            double value = std::stod(buildstr, &nconvert);//convert the string to double, also grabs the number of items converted
            
            if(nconvert!=buildstr.length())
            throw std::invalid_argument("non number was input");

            if(value < min || value > max)
            throw std::out_of_range("out of range");

            return value;
        }
        catch(...){
            std::cout << "Sorry, I cannot understand your answer" << std::endl;
        }

    }
}

/*
   object: pointer to anything - your choice! (but choose something that will be helpful)
   avg: pointer to a double (can store a value here)
*/
void calculateStudentAverage(void *object, double *avg)
{
    Student *student = (Student*)object; //cast to student struct pointer

    // Code to calculate and store average grade
    double sum = 0.0;

    for(int i=0;i<student->n_assignments;i++){
        sum += student->grades[i];
    }
    *avg = sum/student->n_assignments;
}
