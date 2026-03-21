// Source: https://usaco.guide/general/io




#include <bits/stdc++.h>
using namespace std;


#define tcT template<class T
tcT> using V = vector<T>;


class Matrix {
    public:
    int n,m;
    V<V<int>> a;
    Matrix(int n, V<V<int>> a) : n(n), a(a) {}
    int determinant(){
        if(n == 0){
            cout << "cry I guess \n";
        }
        if(n == 1){
            return a[0][0];
        }
        int res = 0;
        for(int i = 0;i < n;i ++){
                // cout << cofactor(i,j) << endl;
                res += a[i][0] * cofactor(i,0);
        }
        return res;
    }
    int cofactor(int i,int j){
        int modifier = (i + j) % 2 == 0 ? 1 : -1;
        return modifier * minor(i,j);
    }
    int minor(int ii, int jj){
        V<V<int>> new_det(n-1,V<int>(n-1));
        for(int i = 0;i < n;i ++){
            if(i == ii) continue;
            for(int j = 0;j < n;j++){
                if(j == jj){
                    continue;
                }
                if(i > ii){
                    if(j > jj){
                        new_det[i-1][j-1] = a[i][j];
                    }else{
                        new_det[i-1][j] = a[i][j];
                    }
                }else{
                    if(j > jj){
                        new_det[i][j-1] = a[i][j];
                    }else{
                        new_det[i][j] = a[i][j];
                    }
                }
            }
        }
        // cout << "new determinant \n";
        // cout << ii << " " << jj << endl;
        // for(auto l : new_det){
        //     for(auto e : l){
        //         cout << e << " ";
        //     }
        //     cout << endl;
        // }
        Matrix new_matrix (n-1,new_det);
        int curr_det = new_matrix.determinant();
        // cout << curr_det << endl;
        return curr_det;
    }
};


int main() {
    int n; cin >> n;
    V<V<int>> a(n,V<int>(n));
    V<int> constant_terms(n);
    for(int i = 0;i  < n;i++){
        for(int j = 0;j <= n;j++){
        if(j != n) cin >> a[i][j];
        else cin >> constant_terms[i];
        }
    }
    Matrix original_matrix(n,a);
    int det = original_matrix.determinant();
    // cout << "det of the original: " << det << '\n';
    V<double> reses;


    for(int ii = 0;ii < n;ii++){
        V<V<int>> new_matrix(n,V<int>(n));


        for(int j = 0;j < n;j ++){
            if(j == ii){
                for(int i = 0;i < n;i ++){
                    new_matrix[i][j] = constant_terms[i];
                }
            }else{
                for(int i = 0;i < n;i ++){
                    new_matrix[i][j] = a[i][j];
                }
            }
        }
        Matrix new_new_matrix(n,new_matrix);
        int curr_det = new_new_matrix.determinant();
        // cout << "curr_det " << curr_det << endl;
        double res = static_cast<double>(curr_det)/static_cast<double>(det);
        reses.push_back(round(res));
    }
    for(int i = 0;i < n-1 ;i++){
        cout << reses[i] << " ";
    }
    cout << reses[n-1] << '\n';
}
