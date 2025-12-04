// #include<iostream>
// #include<string>
// using namespace std;
// int main()
// {
// 	string name1;
// 	string name2;
// 	cout<<"Enter the first string :"<<endl;
// 	getline(cin,name1);
// 	cout<<"Second string:";
// 	getline(cin,name2);
//     name1=name1+" "+name2;
//     cout<<name1;
// 	return 0;
// }
// #include<iostream>
// #include<string>
// using namespace std;
// int main()
// {
// 	string str;
// 	getline(cin,str);
// 	int start=0;
// 	int end=str.length()-1;
// 	while(start<end)
// 	{
// 		int temp;
// 		temp=str[start];
// 		str[start]=str[end];
// 		str[end]=temp;
// 		start++;
// 		end--;
// 	}
// 	cout<<str;
// }




// #include <iostream>
// #include <string>
// using namespace std;

// int main() 
// {
//     string name;
//     cout<<"Enter string";
//     getline(cin,name);

//     string result = "";
//     for (int i=0;i<name.length();i++) {
      
//         if (name[i] != 'a' && name[i] != 'e' && name[i] != 'i' && name[i]!= 'o' && name[i]!= 'u') {
//             result += name[i]; 
//         }
//     }

//     cout<<"String without vowels: "<<result;
//     return 0;
// }




// #include <iostream>
// #include <string>
// using namespace std;

// int main() {
//     int n;
//     string name;
//     getline(cin,name);
//     n=name.length();
//     for(int i=0;i<n-1;i++)
// 	 {
//         for (int j=i+1;j<n;j++)
// 		 {
//             if (name[i]>name[j])
// 			 { 
//                 char temp= name[i];
//                 name[i]=name[j];
//                 name[j]=temp;
//             }
//         }
//     }
//     cout<<name;
//     return 0;
// }




// #include <iostream>
// using namespace std;
// int main() {
//     string name;
//     cout<<"Enter string: ";
//     getline(cin, name);
//     int n=name.length();
//     for (int i=0;i<n;i++) {
//         if (name[i] >= 'A' && name[i]<='Z') {
//             name[i]=name[i] + 32;
//         }
//         else if (name[i]>='a' && name[i]<='z') { 
//             name[i]=name[i]-32;
//         }
//     }
//     cout<<"Toggled string: "<<name<<endl;
//     return 0;
// }



