#include<string.h>
#include<stdlib.h>
//#include<stdio.h>


#define HUD 300

struct Student{
    int id;
    char gender[7];
    int grade;
    int score;
};

static Student ST[HUD+1][20001];
static int num[HUD+1];

void init() {

    for(int i=0;i<HUD+1;i++) num[i] = 0;
	return;
}

int add(int mId, int mGrade, char mGender[7], int mScore) {

    int ID = -1, Score = -1;
    int c = mScore/1000; 
    bool canfind = false;
    ST[c][num[c]].id = mId;
    strcpy(ST[c][num[c]].gender, mGender);
    ST[c][num[c]].grade = mGrade;
    ST[c][num[c]].score = mScore;

    num[c]++;
    for(int i=HUD;i>=0;i--){
        if(canfind) break;
        for(int j=0;j<num[i];j++){
            if(strcmp(ST[i][j].gender,mGender) == 0 && mGrade == ST[i][j].grade){
                if(ST[i][j].score > Score){
                    Score = ST[i][j].score;
                    ID = ST[i][j].id;
                }else if(ST[i][j].score == Score){
                    if(ST[i][j].id > ID){
                        ID = ST[i][j].id;
                    }
                }
                canfind = true;
            }
        }
    }
    
    //printf("%d\n",ID);
	return ID;
}

int remove(int mId) {
    bool canerase = false;
    int ID = 1000000000;
    int Score = 10000000;
    char GENDER[7];
    int GRADE;
    for(int i=0;i<HUD+1;i++){
        if(canerase) break;
        for(int j=0;j<num[i]; j++){
            if(ST[i][j].id == mId){
                canerase = true;
                strcpy(GENDER,ST[i][j].gender);
                GRADE = ST[i][j].grade;
                ST[i][j].id = -1;
                ST[i][j].grade = -1;
                ST[i][j].score = -1;
                strcpy(ST[i][j].gender,"x");
            }
        }
    }

	if(!canerase){
        //printf("%d\n",0);
        return 0;
    }
    else{
        bool canfind = false;
        for(int i=0;i<HUD+1;i++){
            if(canfind) break;
            for(int j=0;j<num[i];j++){
                if(strcmp(ST[i][j].gender,GENDER)==0 && GRADE == ST[i][j].grade){
                    if(ST[i][j].score < Score){
                        Score = ST[i][j].score;
                        ID = ST[i][j].id;
                    }
                    else if(ST[i][j].score == Score){
                        if(ID > ST[i][j].id){
                            ID = ST[i][j].id;
                        }
                    }
                    canfind = true;
                }
            }
        }
        if(!canfind){
            //printf("%d\n",0);
            return 0;
        }
        else{
            //printf("%d\n",ID);
            return ID;
        }
    }
}

int query(int mGradeCnt, int mGrade[], int mGenderCnt, char mGender[][7], int mScore) {
    bool canfind = false;
    int Score = 300000;
    int ID = 1000000000;
    int c = mScore/1000;
    for(int i=c;i<HUD+1;i++){
        if(canfind) break;
        for(int j=0;j<num[i];j++){
            for(int mGrade_ = 0; mGrade_ < mGradeCnt; mGrade_++){
                for(int mGender_ = 0; mGender_ < mGenderCnt; mGender_++){
                    if(strcmp(ST[i][j].gender,mGender[mGender_])==0 && ST[i][j].grade == mGrade[mGrade_] && ST[i][j].score >= mScore){
                        if(ST[i][j].score < Score){
                            Score = ST[i][j].score;
                            ID = ST[i][j].id;
                        }else if(ST[i][j].score == Score){
                            if(ST[i][j].id < ID){
                                ID = ST[i][j].id;
                            }
                        }
                        canfind = true;
                    }
                }
            }
        }
    }
	if(!canfind){
        //printf("%d\n",0);
        return 0;
    }else{
        //printf("%d\n",ID);
        return ID;
    }
}