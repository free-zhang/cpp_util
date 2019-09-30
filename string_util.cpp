#include "string_util.h"

void to_upper(string& s){
    transform(s.begin(), s.end(), s.begin(), ::toupper);
}

void to_lower(string& s){
    transform(s.begin(), s.end(), s.begin(), ::tolower);
}

void reverse(string& s){
    reverse(s.begin(), s.end());
}

bool start_with(const string& s, const string& sStart){
    return (sStart.size() < s.size()) ? false : (s.substr(0, sStart.size()) == sStart);
}

bool end_with(const string& s, const string& sEnd){
    return (sEnd.size() < s.size()) ? false : (s.substr(s.size() - sEnd.size(), sEnd.size()) == sEnd);
}

int switch_letter(int c){
    if(::isupper(c)) return ::tolower(c);
    else if(::islower(c)) return ::toupper(c);
    else return c;
}

void switch_case(string& s){
    transform(s.begin(), s.end(), s.begin(), switch_letter);
}

vector<string> split(const string& sSrc, const string& sSep, bool bRmEmpty){
    if(sSrc.empty()) return {};

    const string sDefault = " \t\n\v\f\r";
    string::size_type pos1 = 0, pos2 = (sSep == sDefault) ? sSrc.find_first_of(sSep) : sSrc.find(sSep);

    vector<string> vRes;
    while(string::npos != pos2){

        if ( !(pos2 == pos1 && bRmEmpty) ){
            vRes.push_back(sSrc.substr(pos1, pos2 - pos1));
        }

        pos1 = pos2 + ((sSep == sDefault) ? 1 : sSep.size());
        pos2 = (sSep == sDefault) ? sSrc.find_first_of(sSep, pos1) : sSrc.find(sSep, pos1);
    }

    if (pos1 != sSrc.length()){
        vRes.push_back(sSrc.substr(pos1));
    }else if (pos1 == sSrc.length() && !bRmEmpty){  // 分隔符在字符串尾部，插入一个空格
        vRes.push_back("");
    }

    return move(vRes);
}

string join(const vector<string>& v, const string& sSep){
    if (v.empty()) return "";

    string sRes = v[0];
    for (int i = 1; i < v.size(); ++i) {
        sRes += sSep + v[i];
    }

    return move(sRes);
}

string replace(const string& sSrc, const string& sOld, const string& sNew){
    string::size_type pos1 = 0, pos2 =  sSrc.find(sOld);
    string sRes(sSrc);

    while(string::npos != pos2){
        sRes.replace(pos2, sOld.size(), sNew);
        pos1 = pos2 + sOld.size();
        pos2 = sRes.find(sOld, pos1);
    }

    return move(sRes);
}

int count(const string& sSrc, const string& sTgt){
    string::size_type pos1 = 0, pos2 =  sSrc.find(sTgt);

    int cnt = 0;
    while(string::npos != pos2){
        cnt++;
        pos1 = pos2 + sTgt.size();
        pos2 = sSrc.find(sTgt, pos1);
    }

    return cnt;
}

void lstrip(string& sSrc, const string& sRm){
    sSrc.empty() ? 0 : sSrc.erase(0, sSrc.find_first_not_of(sRm));
}

void rstrip(string& sSrc, const string& sRm) {
    sSrc.empty() ? 0 : sSrc.erase(sSrc.find_last_not_of(sRm) + 1);
}

void strip(string& sSrc, const string& sRm) {
    lstrip(sSrc, sRm);
    rstrip(sSrc, sRm);
}