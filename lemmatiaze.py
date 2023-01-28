import re
from konlpy.tag import Komoran
komoran = Komoran()
import csv, json
big_ingre = []
regex = "\(.*\)|\s-\s.*"
def lemmatize(raw_dict_str):
    size = len(raw_dict_str)
    for i in range(size):
        ingre_pool = []
        if raw_dict_str[i] == None:
            pass
        else:
            if type(raw_dict_str[i]) != str:
                for j in raw_dict_str[i].values():
                    for k in j:
                        ingre_pool.append(k)
                renew_little_pool = []
                for item in ingre_pool:
                    sp = re.split(r'[0-9]',item)
                    sp[0] = re.sub(regex, '', sp[0])
                    sp[0] = sp[0].replace("조금","").replace("약간","").replace("적당히","").replace("적당량","").replace("구운","").replace("원하는만큼","").replace("많이","").replace("다진","")
                    sp[0] = sp[0].replace("큰것","").replace("작은것","").replace("살짝","").replace("취향껏","").replace("취향것","").replace("▶재료:","").replace("아주","").replace("솔솔","")
                    sp[0] = sp[0].replace("작은","").replace("큰","").replace("소량","").replace("대량","").replace("크게","").replace("껍질벗긴","").replace("손질한","").replace("말린","")
                    sp[0] = re.split('또는',sp[0])[0]
                    sp[0] = re.split('or',sp[0])[0]
                    sp[0] = re.sub(r'\u200b',r'',sp[0])
                    sp[0] = re.sub(r'\u202d',r'',sp[0])
                    sp[0] = re.split('[^가-힣]',sp[0])[0]
                    sp[0] = sp[0].replace("찬","").replace("뜨거운","").replace("더운","").replace("다진","").replace("불린","")
                    sp[0] = sp[0].replace("가나","").replace("는둥만둥","").replace("각각","").replace("가는","").replace("자른","")
                    sp[0] = sp[0].replace("가스오","가쓰오").replace("적당","").replace("국물용말고얇은거","").replace("가위","").replace("것","").replace("썬거","")
                    noun = []
                    for index, item in enumerate(komoran.pos(sp[0])):
                        if item[1] == "NNP" or item[1] == "NNG":
                            noun.append(item[0])
                    sp[0] = "".join(noun)
                    sp[0] = matching(sp[0])
                    if re.search("만큼",sp[0]) or re.match("접시",sp[0]) or re.match("이쑤시개", sp[0]) or sp[0] == "" or re.match("각종",sp[0]):
                        pass
                    else:
                        renew_little_pool.append(re.split('[a-z]',sp[0])[0])
                big_ingre.append(renew_little_pool)











FILE_S0 = 4801
FILE_S1 = 9553
FILE_S2 = 9491
FILE_S3 = 4699
FILE_S4 = 7499

def read_csv_json(size, file):
    raw_dict_str1 = []
    with open(file) as f:
        for i in range(size):
            a = f.readline()
            if a == '[{"\[재료\]":[]}]':
                pass
            else:
                raw_dict_str1.append(a.replace(",",",\"").split("\",\"")[1])
    for i in range(size):
        raw_dict_str1[i] = json.loads(raw_dict_str1[i].replace("\\'","\"").replace(",\"",",").replace("\"{","{").replace("}\"","}").replace("'","\"")[:-1])
    return raw_dict_str1



lemmatize(read_csv_json(FILE_S0,"mangae_recipe.csv"))
