#include <iostream>
#include <fstream>

using namespace std;

const string sogl = "бвгджзйклмнпрстфхцчшщъь";
const string g = "аеёиоуыэюя";

void preload_consts() {
    srand(time(0));
    setlocale (LC_ALL, "Russian");
}

int rand_int(int a, int b) {
    if (b == 0) {
        b = 1;
    }
    return a + rand() % b;
}

string get_alf_line(int letter_pos) {
    string line;

    ifstream readf("alphabet.txt");
    if (!readf.is_open()) {
        cout << "alphabet.txt isn't opened." << endl;
    }
    else {
        for (int i = 0; i < letter_pos; i++) {
            readf >> line >> line;
        }
    }

    //cout << "* * * * * *" << endl;
    //cout << letter_pos << " -> " << line << endl;
    //cout << "* * * * * *" << endl;

    readf.close();
    return line;
}

string get_rand_letter(string line) {
    string letter;

    letter = line[rand_int(0, line.size())];

    //cout << "- - - - -" << endl;
    //cout << line << " -> " << letter << endl;
    //cout << "- - - - -" << endl;

    return letter;
}

int analyth_letter(char letter) {
    string alf = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    for (int i = 0; i < alf.size(); i++) {
        if (alf[i] == letter) {
            return i + 1;
        }
    }
    return 0;
}

bool Rule_1(string word) {

    return true;
}

string word_generate(int word_length) {
    int letter_num;

    string word;

    word = word + get_rand_letter(get_alf_line(34));
    for (int i = 0; i < word_length; i++) {
        letter_num = analyth_letter(word[i]);
        word = word + get_rand_letter(get_alf_line(letter_num));
    }
    return word;
}

int main()
{
    preload_consts();

    for (int i = 0; i < 20; i++) {
        cout << word_generate(5) << endl;
    }
    /*
    for (int i = 0; i < 10; i++) {
        get_rand_letter(get_alf_line(rand_int(1, 33)));
    }
    */
    return 0;
}