#include "Series_Search.h"
#include "Episode_Search.h"
#include "RU_Titles.h"
#include "EN_Titles.h"

using namespace std;

int Parse_Args(int argc, char* argv[], string& Basics_Name, string& Episode_Name, string& Akas_Name, string& Series_Name) {
    cout << "Разместите файлы в одной директории с исполняемым файлом!" << endl;
    cout << "Название сериала возьмите в кавычки!" << endl << endl;

    if (argc != 5) {
        cout << "Usage: " << argv[0] << " <basics.tsv> <episode.tsv> <akas.tsv> \"seriesname\"" << endl;
        return 1;
    }

    Basics_Name = argv[1];
    Episode_Name = argv[2];
    Akas_Name = argv[3];
    Series_Name = argv[4];

    return 0;
}


int main(int argc, char* argv[]) {	
    setlocale(LC_ALL, "Russian");
    string Basics_Name, Episode_Name, Akas_Name, Series_Name;

    int code = Parse_Args(argc, argv, Basics_Name, Episode_Name, Akas_Name, Series_Name);

    if (code == 1) {
    	return 1;
    };

	ifstream Basics;
	ifstream Episode;
	ifstream Akas;

    //открываем используемые файлы
	try{
		Basics.open(Basics_Name);
		Episode.open(Episode_Name);
		Akas.open(Akas_Name);
	} catch (...){
		cout<<"File_Problem"<<endl;
	}
	
	cout<<"Поиск ID сериала ..."<<endl;
    vector<string> Series_ID = Series_Search(Basics, Series_Name);//получаем id искомого сериала
	cout<<"ID сериала "<<Series_ID[0]<<endl<<endl;

    //проверка на 18+
	if (Series_ID[4] == "1") {
		cout<<"Фильм для взрослых"<<endl<<endl;
		return 0;
	}

	cout<<"Поиск ID эпизодов ..."<<endl;
    vector<string> Episode_Ids = Episode_Search(Episode, Series_ID[0]);//получаем id эпизодов
	cout<<"Количество эпизодов "<<Episode_Ids.size()<<endl<<endl;
	
    //for (int i = 0; i < Episode_Ids.size(); i++) {
    //	cout<<"Episode_Id "<<Episode_Ids[i]<<endl;
    //}
    
    cout<<"Поиск названий эпизодов на русском ..."<<endl;
    vector<string> Episode_Titles = RU_Titles(Akas, Episode_Ids);//ищем эпизоды на русском (их в дс практически нет)

	cout<<"Эпизодов на русском "<<Episode_Titles.size()<<endl<<endl;

    //если не нашли ни одного эпизода на русском, берем их названия на англ
	if (Episode_Titles.size()==0){
		cout<<"Поиск названий эпизодов на английском ..."<<endl;
		Episode_Titles = EN_Titles(Basics, Episode_Ids);
	}
	
	
    //вывод названий эпизодов
    for (auto i : Episode_Titles) {
        cout<<i<<endl;
	}
	
	//cout<<"cout_debug"<<endl;
	

    //закрываем файлы
	Basics.close();
	Episode.close();
	Akas.close();

    return 0;
}
