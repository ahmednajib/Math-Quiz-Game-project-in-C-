#include <iostream>
using namespace std;

enum enQuestionLevel { Easy = 1, Med = 2, Hard = 3, Mix = 4 };
enum enOperationType { Add = 1, Sub = 2, Mul = 3, Div = 4, mix = 5 };
enum enStatus{Passed = 1, Failed = 2};

struct stQuizInfo {
    short NumOfQuestios = 0;
    short TrueAnswer = 0;
    enQuestionLevel QuestionLevel;
    enOperationType OperationType;
    enStatus Status;

};

struct stQuizResult {
    short Qnumber = 0;
    enQuestionLevel QuestionLevel;
    enOperationType OperationType;
    short RightAnswers = 0;
    short WrongAnswers = 0;
    enStatus Status;
};

int RandomNumber(int From, int To) {

    int RandumNumber = rand() % (To - From + 1) + From;
    return RandumNumber;
}

short ReadPositiveNumber() {
    short Number = 0;
    do {
        cin >> Number;

    } while (Number < 0);
    return Number;
}

int ReadNumberInRange(int From, int To) {
    int Number = 0;
    do {

        cin >> Number;
    } while (Number < From || Number > To);

    return Number;
}

void ResetScreen() {
    system("cls");
    system("color 0F");
}

enQuestionLevel QuestionLevel() {
    cout << "Please Enter Questions Level : [1] Easy, [2] Med, [3] Hard, [4] Mix ?";
    short  QLevel = ReadNumberInRange(1, 4);

    return (enQuestionLevel)QLevel;
}

enOperationType OperationType() {
    cout << "Please Enter OperationType : [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ?";
    short  OpType = ReadNumberInRange(1, 5);

    return (enOperationType)OpType;
}

char MixOpType() {
    short MixType = 0;
    do {
        MixType = RandomNumber(42, 47);
    } while (MixType == 44 || MixType == 46);

    return char(MixType);
}

bool Quiz(enQuestionLevel Level, enOperationType OpType, short& TrueAnswer) {
    short Result = 0;
    short Num1 = 0, Num2 = 0;
    char MixType = '!';
    
    switch (Level)
    {
    case ( enQuestionLevel::Easy ):
        Num1 = RandomNumber(1, 9);
        Num2 = RandomNumber(1, 9);
     break;

    case (enQuestionLevel::Med):
        Num1 = RandomNumber(10, 15);
        Num2 = RandomNumber(10, 15);
        break;

    case (enQuestionLevel::Hard):
        Num1 = RandomNumber(15,20);
        Num2 = RandomNumber(15, 20);
        break;

        case (enQuestionLevel::Mix) :
            Num1 = RandomNumber(1, 20);
            Num2 = RandomNumber(1, 20);
            break;
    }

    
    switch (OpType)
        {
        case(enOperationType::Add):
            cout << Num1 << "\n\t + \n" << Num2 << "\n----------------\n";
            cin >> Result;

            TrueAnswer = Num1 + Num2;
            if (Result == TrueAnswer)
                return true;
            else return false;
            break;

        case(enOperationType::Sub):
            cout << Num1 << "\n\t - \n" << Num2 << "\n----------------\n";
            cin >> Result;

            TrueAnswer = Num1 - Num2;
            if (Result == TrueAnswer)
                return true;
            else return false;
            break;

        case(enOperationType::Mul):
            cout << Num1 << "\n\t * \n" << Num2 << "\n----------------\n";
            cin >> Result;
            TrueAnswer = Num1 * Num2;
            if (Result == TrueAnswer)
                return true;
            else return false;
            break;

        case(enOperationType::Div):
            cout << Num1 << "\n\t / \n" << Num2 << "\n----------------\n";
            cin >> Result;
            TrueAnswer = Num1 / Num2;
            if (Result == TrueAnswer)
                return true;
            else return false;
            break;

        case(enOperationType::mix):
            MixType = MixOpType();
            cout << Num1 << "\n\t " << MixType << "\n" << Num2 << "\n----------------\n";
            cin >> Result;
            if (MixType == '*')
                TrueAnswer = Num1 * Num2;

            else if (MixType == '+')
                TrueAnswer = Num1 + Num2;
            else if (MixType == '-')
                TrueAnswer = Num1 - Num2;

            else
                TrueAnswer = Num1 / Num2;

            if (Result == TrueAnswer)
                return true;
            else return false;
            break;

        }
    
    }

void PrintResult(bool Result, short RightAnswer) {
    if (Result) {
        cout << "Right Answer :-)\n";
        system("color 2F ");
    }
    else {
        cout << "Wrong Answer :-( \nThe right Answer is : " << RightAnswer << endl;
        system("color 4F ");
        cout << "\a";

    }
}

enStatus PassOrFailed(short RightAnswers, short WrongAnswers) {

    if (RightAnswers >= WrongAnswers)
        return enStatus::Passed;
    else 
        return enStatus::Failed;
}

stQuizResult FillQuizResults(stQuizInfo QuizInfo, short RightAnswers, short WrongAnswers) {
    stQuizResult QuizResult;
    QuizResult.Qnumber = QuizInfo.NumOfQuestios;
    QuizResult.QuestionLevel = QuizInfo.QuestionLevel;
    QuizResult.OperationType = QuizInfo.OperationType;
    QuizResult.Status = QuizInfo.Status;
    QuizResult.RightAnswers = RightAnswers;
    QuizResult.WrongAnswers = WrongAnswers;

    return QuizResult;

}

string StatusString(enStatus Status) {
    string arr[2] = {"Passed", "Failed"};
    return arr[Status - 1];
}

string QuestionlevelString(enQuestionLevel Qlevel) {
    string arr[4] = { "Easy", "Med", "Hard","Mix" };
    return arr[Qlevel - 1];
}

string OperationTypeString(enOperationType OpType) {
    string arr[5] = { "Add", "Sub", "Mul", "Div", "Mix" };
    return arr[OpType - 1];
}

stQuizResult Rounds() {
    stQuizInfo QuizInfo;
    cout << "How many questions do you want ? \n";
    short QuestionNumbers = ReadNumberInRange(1,100);
    short RightAnswers = 0, WrongAnswers = 0;
    bool Result = true;
    QuizInfo.QuestionLevel = QuestionLevel();
    QuizInfo.OperationType = OperationType();
    QuizInfo.NumOfQuestios = QuestionNumbers;
    for (int i = 1; i <= QuestionNumbers; i++)
    {
        cout << "Question [ " << i << " / " << QuestionNumbers << " ] \n";
        Result = Quiz(QuizInfo.QuestionLevel, QuizInfo.OperationType, QuizInfo.TrueAnswer);

        PrintResult(Result,QuizInfo.TrueAnswer);
        if (Result)
            RightAnswers++;
        else
            WrongAnswers++;
    }
    QuizInfo.Status = PassOrFailed(RightAnswers, WrongAnswers);

    return FillQuizResults(QuizInfo, RightAnswers, WrongAnswers);
}

void FinalResults(stQuizResult QuizResult) {
    cout << "\n---------------------------------------------------------------\n";
    cout << "Final Result is " << StatusString(QuizResult.Status) << endl;
    cout << "\n---------------------------------------------------------------\n\n";
    cout << "Number of questions        : " << QuizResult.Qnumber << endl;
    cout << "Question level             : " << QuestionlevelString(QuizResult.QuestionLevel) << endl;
    cout << "Operation Type             : " << OperationTypeString(QuizResult.OperationType) << endl;
    cout << "Number of right Answers   : " << QuizResult.RightAnswers << endl;
    cout << "Number of wrong Answers   : " << QuizResult.WrongAnswers << endl;

}

void StartQuiz() {
    char PlayAgain = 'y';
    do {
        ResetScreen();
        stQuizResult QuizResult = Rounds();
        FinalResults(QuizResult);
        cout << "Dou you want to play again ? y / n ? \n";
        cin >> PlayAgain;
    } while (PlayAgain == 'y' || PlayAgain == 'Y');

}

int main()
{
    srand((unsigned)time(NULL));
    StartQuiz();
    return 0;
}