// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int r,c,n;
//     cout<<"Enter rows ,cols and number of non zero elements : ";
//     cin>>r>>c>>n;

//     int arr[n][3];
//     cout<<"Enter rows ,cols and value of non zero elements : ";
//     for(int i=0;i<n;i++){
//         cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
//     }

//     cout<<"Row Col Value"<<endl;
//     for(int i=0;i<n;i++){
//         cout<<arr[i][0]<<"   "<<arr[i][1]<<"   "<<arr[i][2]<<" "<<endl;
//     }

//     for (int i=0;i<n;i++) {
//         int temp = arr[i][0];
//         arr[i][0] = arr[i][1];
//         arr[i][1] = temp;
//     }
//     cout<<"Transpose : \n";
//      cout<<"Row Col Value"<<endl;
//     for(int i=0;i<n;i++){
//         cout<<arr[i][0]<<"   "<<arr[i][1]<<"   "<<arr[i][2]<<" "<<endl;
//     }
//     return 0;
// }







// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int r, c, n1, n2;
//     cout << "Enter rows and cols of matrices: ";
//     cin>>r>>c;
//     cout<<"Enter number of non-zero elements in Matrix A: ";
//     cin>>n1;

//     int A[n1][3];
//     cout << "Enter row, col, val for Matrix A:\n";
//     for (int i=0;i<n1;i++) {
//         cin>>A[i][0]>>A[i][1]>>A[i][2];
//     }

//     cout<<"Enter number of non-zero elements in Matrix B: ";
//     cin>>n2;

//     int B[n2][3];
//     cout <<"Enter row, col, val for Matrix B:\n";
//     for (int i=0;i<n2;i++) {
//         cin>>B[i][0]>>B[i][1]>>B[i][2];
//     }

//     cout<<"Result of Addition (Triplet form):\n";
//     cout<<"Row Col Val\n";


//     int i=0,j=0;
//     while(i<n1 && j<n2){
//         if(A[i][0] == B[j][0] && A[i][1] == B[j][1]) {
//             cout<<A[i][0]<<" "<<A[i][1]<<" "<<A[i][2]+B[j][2]<<endl;
//             i++;
//             j++;
//         } 
//         else if(A[i][0]<B[j][0] || (A[i][0]==B[j][0] && A[i][1]<B[j][1])) {
//             cout<<A[i][0]<<" "<<A[i][1]<<" "<<A[i][2]<<endl;
//             i++;
//         } 
//         else{
//             cout<<B[j][0]<<" "<<B[j][1]<<" "<<B[j][2]<<endl;
//             j++;
//         }
//     }
//     while(i<n1){
//         cout<<A[i][0]<<" "<<A[i][1]<<" "<<A[i][2]<<endl;
//         i++;
//     }
//     while(j<n2){
//         cout<<B[j][0]<<" "<<B[j][1]<<" "<<B[j][2]<<endl;
//         j++;
//     }
//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int r1,c1,n1,r2,c2,n2;
//     cout<<"Enter rows, cols and non-zero count for Matrix A: ";
//     cin>>r1>>c1>>n1;
//     int A[n1][3];
//     cout<<"Enter row col val for Matrix A:\n";
//     for(int i=0;i<n1;i++) {
//         cin>>A[i][0]>>A[i][1]>>A[i][2];
//     }

//     cout<<"Enter rows, cols and non-zero count for Matrix B: ";
//     cin>>r2>>c2>>n2;
//     int B[n2][3];
//     cout<<"Enter row col val for Matrix B:\n";
//     for(int i=0;i<n2;i++) {
//         cin>>B[i][0]>>B[i][1]>>B[i][2];
//     }

//     if(c1!=r2) {
//         cout<<"Multiplication not possible!\n";
//         return 0;
//     }

//     cout<<"Result of Multiplication"<<endl;
//     cout<<"Row Col Val\n";

    
//     for (int i=0;i<n1;i++) {
//         for (int j=0;j<n2;j++) {
//             if(A[i][1] == B[j][0]) { 
//                 cout<<A[i][0]<<" "<<B[j][1]<<" "<<A[i][2]*B[j][2]<<endl;
//             }
//         }
//     }
//     return 0;
// }