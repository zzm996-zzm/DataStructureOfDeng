#pragma once  
#include <cstring>
#include <unistd.h>
#include "../_share/util.hpp"
#include "../ch02/Vector.hpp"

struct SuperCharacter {
    bool marked;
    char c;
    SuperCharacter() = default;
    SuperCharacter(char k, bool b = false):c(k), marked(b){}
};//For display 


class String {
public:
    String();//默认构造函数
    String(const char* s);//C风格字符串的构造函数
    String(const String& );//拷贝构造函数
    String(const char* s, size_type k);//从位置s开始构造k个字符

    ~String() { delete[] data_; }//析构函数
    String& operator=(const String&);//拷贝赋值运算符

    const char& front() const;//第一个元素
    const char& back()  const;//最后一个元素
    bool check(int i) const;//下标越界检查
    const char* c_str() const;//C风格字符串

    size_type size() const {  return end_ - data_; }//大小
    bool empty() const {    return end_ == data_;   }//判空

    char charAt(size_type i)/* 返回对应字符前进行下标检查 */{   if(check(i))  return (*this)[i]; return '\0';}
    String substr(size_type i, size_type k);//返回从i开始的k个字符的子串
    String prefix(size_type k);//返回前缀
    String suffix(size_type k);//返回后缀
    bool equal(const String& rhs)/* 判等 */ {   return *this == rhs;  }
    String& concat(const String& rhs);//字符串拼接
    int indexOf(const String& rhs);//子串匹配

    char& operator[](size_type r);//重载下标运算符
    bool operator==(const String& rhs);//重载判等运算符
    bool operator!=(const String& rhs) {    return !(*this == rhs);     }

    /* display */
    int displayBruteForce1(const String& P);
    int displayBruteForce2(const String& P);
    int displayKMP(const String& P);

private:
    int BruteForce1(const String& P);
    int BruteForce2(const String& P);
    int* buildNext(const String& P);
    int KMP(const String& P);
    char* data_;
    char* end_;
};

String::String():data_(new char[1])
{
    *data_ = '\0';
    end_ = data_;
}

String::String(const char* s):data_(new char[strlen(s)+1]){
    strcpy(data_, s);
    end_ = data_ + strlen(s);
}

String::String(const String& rhs){
    int size = strlen(rhs.c_str());
    data_ = new char[size+1];
    strcpy(data_, rhs.c_str());
    end_ = data_ + strlen(rhs.c_str());
}

String::String(const char* s, size_type k){
    data_ = new char[k+1];
    int i;
    for(i = 0; i < k; i++){
        data_[i] = s[i];
    }
    data_[i] = '\0';
    end_ = &data_[i];
}

const char& String::front() const {
    return *data_;
}

const char& String::back() const {
    return *(end_ - 1);
}

char& String::operator[](size_type r){
    return data_[r];
}

const char* String::c_str() const{
    return data_;
}

String& String::operator=(const String& rhs){
    if(&rhs != this){
        const char* temp = rhs.c_str();
        delete[] data_;
        data_ = new char[strlen(temp)+1];
        strcpy(data_, temp);
        end_ = data_ + strlen(temp);
    }
    return *this;
}

bool String::check(int i) const
{
    if (i >= this->size()) 
        return false;
    return true;
}

String String::substr(size_type i, size_type k){
    String ret;
    if(check(i)){
        size_type comp = this->size() - i;

        size_type size = lt(k, comp)?k:comp;
        printf("size:  %u\n", size);
        String str(data_+i, size);
        ret = str;
    }
    return std::move(ret);
}

bool String::operator==(const String& rhs){
    if(!strcmp(this->data_, rhs.data_))
        return true;
    return false;
}

String String::prefix(size_type k){
    if(check(k))
        return String(this->data_, k);
    return String(*this);
}

String String::suffix(size_type k){
    if(check(k))
        return String(this->end_ - k, k);
    return String(*this);
}

String& String::concat(const String& rhs){
    size_type l = this->size();
    size_type r = rhs.size();
    size_type sum = l+r;
    char* n = new char[sum+1];
    int i;
    for(i = 0; i < l; i++){
        *(n+i) = (*this)[i];
    }

    for(int j = 0; j < r && i < sum; i++, j++){
        *(n+i) = *(rhs.data_ +j);
    }

    *(n+i) = '\0';
    end_ = n+i;

    delete[] data_;
    data_ = n;
    return *this;
}

int
String::indexOf(const String& rhs){
    return KMP(rhs);
}

int 
String::BruteForce1(const String& P){
    size_type n = this->size(), i = 0;
    size_type m = P.size(), j = 0;

    while(j < m && i < n)
        if(this->data_[i] == P.data_[j]){
            i++;
            j++;
        } else {
            i -= j - 1;
            j = 0;
        }
    return i - j;
}

int 
String::BruteForce2(const String& P){
    size_type n = this->size(), i;
    size_type m = P.size(), j;
    for(i = 0; i < n - m + 1; i++){
        for(j = 0; j < m; j++)
            if(this->data_[i+j] != P.data_[j]) break;
        if(j >= m) break;//找到后立即跳出 
    }
    return i;
}

int
String::KMP(const String& P){
    int* next = buildNext(P);

    //print next table
    putchar(' ');
    for(int a = 0; a < P.size(); a++){
        putchar(P.data_[a]);
        putchar(' ');
    }
    putchar('\n');
    for(int a = 0; a < P.size(); a++){
        printf("%d ", next[a]);
    }
    putchar('\n');
    //print next table
    

    int n = (int)this->size(), i = 0;
    int m = (int)P.size(), j = 0;
    while(j < m && i < n)
        if(j < 0 || this->data_[i] == P.data_[j]){
            i++;
            j++;
        } else 
            j = next[j];
    delete[] next;
    return i - j;
}

int* 
String::buildNext(const String& P){
    size_type m = P.size(), j = 0;
    int* N = new int[m];
    int t = N[0] = -1;
    while(j < m - 1)
        if(t < 0 || P.data_[j] == P.data_[t]){//短路求值
            j++;
            t++;
            N[j] = t;
        } else 
            t = N[t];
    return N;
}

int 
String::displayBruteForce1(const String& P){
    size_type n = this->size(), i = 0;
    size_type m = P.size(), j = 0;

    size_type fixed = 0;

    Vector<SuperCharacter> source;
    Vector<SuperCharacter> pattern;

    for(int a = 0; a < n; a++){
        source.insert(SuperCharacter(this->data_[a]));   
    }

    for(int a = 0; a < m; a++){
        pattern.insert(SuperCharacter(P.data_[a]));
    }
    system("clear");
    while(j < m && i < n){
        
        if(source[i].c == pattern[j].c){
            source[i].marked = true;
            pattern[j].marked = true;
            i++;
            j++; 
        } else {
            int clear_for_i = i;
            int clear_for_j = j;

            i -= j - 1;
            fixed = i;
            
            j = 0;
            for(int a = i; a <= clear_for_i; a++)
                source[a].marked = false;
            for(int a = j; a <= clear_for_j; a++)
                pattern[a].marked = false;
        }

        printf("Source String:  ");
        for(int iter = 0; iter != n; iter++){
            if(source[iter].marked == true)
                printf("\033[0m\033[1;31m%c\033[0m",source[iter].c);
            else 
                printf("%c",source[iter].c);
        }
        putchar('\n');

        printf("Pattern String: ");
        for(int iter = 0; iter < fixed; iter++)
            putchar(' ');
        for(int iter = 0; iter != m; iter++){
            if(pattern[iter].marked == true)
                printf("\033[0m\033[1;31m%c\033[0m",pattern[iter].c);
            else 
                printf("%c",pattern[iter].c);
        }
        putchar('\n');
        sleep(1);
        system("clear");
    }

    return i - j;
}


int 
String::displayBruteForce2(const String& P){
    size_type n = this->size(), i;
    size_type m = P.size(), j;
    size_type fixed = 0;

    bool flag = false;

    Vector<SuperCharacter> source;
    Vector<SuperCharacter> pattern;

    for(int a = 0; a < n; a++){
        source.insert(SuperCharacter(this->data_[a]));   
    }

    for(int a = 0; a < m; a++){
        pattern.insert(SuperCharacter(P.data_[a]));
    }

    system("clear");
    for(i = 0; i < n - m + 1; i++){

        for(j = 0; j < m; j++){
            if(source[i+j].c != pattern[j].c) {
                flag = false;
                for(int iter = 0; iter < j; iter++){
                    source[i+iter].marked = false;
                    pattern[iter].marked = false;
                }
                break;
            } else {
                flag = true;
                source[i+j].marked = true;
                pattern[j].marked = true;

                printf("Source String:  ");
                for(int iter = 0; iter != n; iter++){
                    if(source[iter].marked == true)
                        printf("\033[0m\033[1;31m%c\033[0m",source[iter].c);
                    else 
                        printf("%c",source[iter].c);
                }
                putchar('\n');

                printf("Pattern String: ");
                for(int iter = 0; iter < i; iter++)
                    putchar(' ');
                for(int iter = 0; iter != m; iter++){
                    if(pattern[iter].marked == true)
                        printf("\033[0m\033[1;31m%c\033[0m",pattern[iter].c);
                    else 
                        printf("%c",pattern[iter].c);
                }
                putchar('\n');
                sleep(1);
                system("clear");
            }

        }

        if(flag == false){
            printf("Source String:  ");
            for(int iter = 0; iter != n; iter++){
                if(source[iter].marked == true)
                    printf("\033[0m\033[1;31m%c\033[0m",source[iter].c);
                else 
                    printf("%c",source[iter].c);
            }
            putchar('\n');

            printf("Pattern String: ");
            for(int iter = 0; iter < i; iter++)
                putchar(' ');
            for(int iter = 0; iter != m; iter++){
                if(pattern[iter].marked == true)
                    printf("\033[0m\033[1;31m%c\033[0m",pattern[iter].c);
                else 
                    printf("%c",pattern[iter].c);
            }
            putchar('\n');
            sleep(1);
            system("clear");
        }        

        if(j >= m) break;//找到后立即跳出 
    }
    return i;
}