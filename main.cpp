#include "Series_Search.h"
#include "Episode_Search.h"
#include "RU_Titles.h"
#include "EN_Titles.h"

using namespace std;

int main(int argc, char* argv[]) {	
	setlocale(LC_ALL, "Russian");
	cout << "Разместите передаваемые в аргументы файлы в одной директории с исполняемым файлом" << endl;
	cout << "Название сериала возьмите в кавычки" << endl;
    if (argc != 5) {
        cout << "Usage: " << argv[0] << " <basics.tsv> <episode.tsv> <akas.tsv> \"seriesname\"" << endl;    
        
        return 1;
    }
    
    string Basics_Name = argv[1];
    string Episode_Name = argv[2];
    string Akas_Name = argv[3];
    string Series_Name = argv[4];

	ifstream Basics;
	ifstream Episode;
	ifstream Akas;
	try{
		Basics.open(Basics_Name);
		Episode.open(Episode_Name);
		Akas.open(Akas_Name);
	} catch (...){
		cout<<"File_Problem"<<endl;
	}
	
	vector<string> Series_ID = Series_Search(Basics, Series_Name);
	cout<<"ID сериала "<<Series_ID[0]<<endl;
	if (Series_ID[4] == "1") {
		cout<<"Фильм для взрослых"<<endl;
		return 0;
	}
	vector<string> Episode_Ids = Episode_Search(Episode, Series_ID[0]);
	cout<<"Количество эпизодов "<<Episode_Ids.size()<<endl;
	
	//for (int i = 0; i < Episode_Ids.size(); i++) {
    //	cout<<"Episode_Id "<<Episode_Ids[i]<<endl;
    //}
    
	vector<string> Episode_Titles = RU_Titles(Akas, Episode_Ids);
	cout<<"Эпизодов на русском "<<Episode_Titles.size()<<endl;
	if (Episode_Titles.size()==0){
		Episode_Titles = EN_Titles(Basics, Episode_Ids);
	}
	
	
	
	for (int i = 0; i < Episode_Titles.size(); i++) {
		cout<<Episode_Titles[i]<<endl;
	}
	
	//cout<<"cout_debug"<<endl;
	
	Basics.close();
	Episode.close();
	Akas.close();
    return 0;
}
