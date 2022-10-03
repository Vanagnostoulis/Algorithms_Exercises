#include <bits/stdc++.h>  
#include <vector>  
#define BSIZE 1<<15  
using namespace std;  
char buffer[BSIZE];  
long bpos = 0L, bsize = 0L;  
long readLong()  
{  
    long d = 0L, x = 0L;  
    char c;  
    while (1)  {  
        if (bpos >= bsize) {  
            bpos = 0;  
            if (feof(stdin)) return x;  
            bsize = fread(buffer, 1, BSIZE, stdin);  
        }  
        c = buffer[bpos++];  
        if (c >= '0' && c <= '9') { x = x * 10 + (c - '0'); d = 1; }  
        else if (d == 1) return x;  
    }  
    return -1;  
}  
struct particles  
{  
    double distance;  
    long speed;  
    long time;  
    long id;  
};  
int main()  
{  
    long n, l, k, lowerspeed;  
    double time_max;  
    n = readLong();  
    l = readLong();  
    k = readLong();  
    vector<particles> a;  
    vector<particles> b;  
    lowerspeed = LONG_MAX;  
    for (long i = 0; i < n; ++i)  
    {  
        a.push_back(particles());  
        a[i].time = readLong();  
        a[i].speed = readLong();  
        if (a[i].speed < lowerspeed)  
            lowerspeed = a[i].speed;  
        a[i].id = i + 1;  
    }  
    for (long i = 0; i < n; ++i)  
    {  
        b.push_back(particles());  
        b[i].time = readLong();  
        b[i].speed = readLong();  
        if (b[i].speed < lowerspeed)  
            lowerspeed = b[i].speed;  
        b[i].id = i + 1;  
    }  
    time_max = b[n - 1].time;  
    if (time_max <  a[n - 1].time)  
        time_max = a[n - 1].time;  
    time_max = ((( 1.0 * l) / (1.0 * lowerspeed)) + time_max);  
    double max_a, min_b, left, mid, right;  
    long max_a_id, min_b_id, index_a, index_b, index_counter;  
    right = time_max;  
    left = 0;  
    //  FINE /////////////////////// FINE ////////////////////////////////////////// FINE  
    max_a = 0;  //dont care only used in first loop  
    min_b = 1;  //dont care only used in first loop  
    while (k != 0)  
    {  
        mid = ((left + right) / 2);  
        if (right - left <= 0.001)  
        {  
            cout << max_a_id << " " << min_b_id << endl;  
            //cout << endl << " A > B " << max_a_id << " " << min_b_id << endl << endl;  
            //cout << "deleted INDEX_A: " << index_a << " with ID: " << a[index_a].id << endl;  
            //cout << "deleted INDEX_B: " << index_b << " with ID: " << b[index_a].id << endl;  
            a.erase(a.begin() + index_a);  
            b.erase(b.begin() + index_b);  
            left = right;  
            right = time_max;  
            k--;  
            continue;  
        }  
        //cout << endl << "LEFT: " << left << " RIGHT: " << right << " MID: " << mid << endl;  
        max_a = -1;  
        max_a_id = -1;  
        index_a = -1;  
        index_counter = -1;  
        for (vector<particles>::iterator i = a.begin(); i != a.end(); ++i)  
        {  
            index_counter++;  
            if (mid > i->time)  
            {  
                i->distance = i->speed * (mid - i->time);  
                if (i->distance > max_a)  
                {  
                    index_a = index_counter;  
  
                    max_a = i->distance;  
                    max_a_id = i->id;  
                }  
            }  
            else  
                break;  
        }  
        min_b = l + 0.0001;  
        min_b_id = -1;  
        index_b = -1;  
        index_counter = -1;  
        for (vector<particles>::iterator i = b.begin(); i != b.end(); ++i)  
        {   index_counter++;  
            if (mid > i->time)  
            {  
                i->distance = (l - (i->speed * (mid - i->time)));  
                if (i->distance < min_b)  
                {  
                    index_b = index_counter;  
  
                    min_b_id = i->id;  
                    min_b = i->distance;  
                }  
            }  
            else  
                break;  
        }  
        //cout << endl << "MAX A: " << max_a << " MIN B: " << min_b << endl;  
        if (max_a > min_b)  
        {  
            right = mid;  
            continue;  
        }  
        else if (max_a < min_b)  
        {  
            left = mid;  
            continue;  
        }  
    }  
}  