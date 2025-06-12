#include<iostream>
#include<vector>
using namespace std;

int main(){
    //creation
     vector<int> marks;
     vector<int> newmarks;
     vector<int> miles(10);// size: 10
     vector<int> distances(15,0);//size: 15 and insert value 5

    //begin()
    // cout<<*(miles.begin())<<endl;

    //push_back()
    marks.push_back(10);
    marks.push_back(20);
    marks.push_back(30);
    marks.push_back(40);
    marks.push_back(50);
//     int n= marks.size();

//     for(int i=0;i<n;i++){
//         cout<< marks[i]<<" ";
//     }
//     return 0;
// }

// clear
//  marks.clear();

//insert
marks.insert(marks.begin(),50);

//erase
marks.erase(marks.begin());
marks.pop_back();

//reserve()
marks.reserve(10);

//size
cout<< "size:"<<marks.size()<<endl;

//capacity()
cout<<"capacity :"<<marks.capacity()<<endl;

//max_size()
cout<< "max size :"<<marks.max_size()<<endl;

//pop_back()
// marks.pop_back();

//front()
cout<<"marks.front:"<<marks.front()<<endl;

//back
cout<<"marks.back:"<<marks.back()<<endl;

//empty()
if(marks.empty()==true){
    cout<<"vector is empty"<<endl;
}
else{
    cout<<"vector is not empty"<<endl;
}

//operator
marks[0]=100;
cout<<marks.at(0)<<endl; // at
// marks[0]-> makes.at(0);

newmarks.push_back(100);
newmarks.push_back(200);
newmarks.push_back(300);
newmarks.push_back(400);
newmarks.push_back(500);


//swap()
newmarks.swap(marks);

vector<int>:: iterator it= marks.begin();
while(it!= marks.end()){
    cout<<*it<<" ";
    it++;
}

  return 0;
}