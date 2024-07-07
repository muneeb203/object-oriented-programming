
#include <iostream>
#include <string>
using namespace std;

class Hadiths {
    private:
        string hadith;
    public:
        Hadiths(string hadith) {
            this->hadith = hadith;
        }
        string* updateHadith() {
            for(int i=0; i<hadith.length(); i++) {
                if(i==0 || hadith[i-1]==' ') {
                    hadith[i] = toupper(hadith[i]);
                } else {
                    hadith[i] = tolower(hadith[i]);
                }
            }
            return &hadith;
        }
};

int main() {
    Hadiths hadith1("abu Hurayrah narrated that Prophet Muhammad (PBUH) said: \n “Fasting is a shield, so when one of you is fasting, he should neither indulge in obscene language nor should he raise his voice in anger. If someone attacks him or insults him, let him say: I am fasting”.  \t\t\t (Muslim)");
    Hadiths hadith2("abdullah ibn `Amr reported that the Prophet (peace and blessings be upon him) said\n, Fasting and the Quran will intercede on behalf of Allah\'s servant on the Day of Judgment: Fasting will say, “O my Lord! I prevented him from food and desires during the day, so accept my intercession for him.And the Quran will say, “O my Lord! I prevented him from sleeping by night, so accept my intercession for him.The intercession of both will thus be accepted.");

    string* updatedHadith1 = hadith1.updateHadith();
    string* updatedHadith2 = hadith2.updateHadith();

    cout << "Updated Hadith 1: " << *updatedHadith1 << endl<<endl;
    cout << "Updated Hadith 2: " << *updatedHadith2 << endl;

    return 0;
}
