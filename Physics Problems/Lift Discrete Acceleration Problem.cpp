#include <iostream>
#include <cmath>

using namespace std;
/* ASSUMING LIFT OF LENGTH 500KM IE. COM = 250KM (lift touches the ground when com is 250km above)
   POINT A = 100 KM above COM OF LIFT 
   POINT B = 100 KM below COM of lift
*/
int main()
{
    const float len_lift = 500;
    float height_com = len_lift/2;

    float const WT_a=.01,WT_b=0.01,WT_lift=500;
                                             // 500kg assumed for lift
                                             // 10 grams for a and b

    float const Dis_a = +100;
    float const Dis_b = -100;         //Assuming lift com at 0 and value given here is wrt that.
    const float R = 6400;
    float res_g_lift[6000],res_g_a[6000],res_g_b[6000];
    const float g = 9.728688;                      // at surface 6400km
    float force_lift[6000],force_b[6000],force_a[6000];     // to store force at lift , point a and point b.
    
    float diff_force_a_lift[6000],diff_force_b_lift[6000];  /*diff_force_b_lift : force on B - force on Lift
                                                            (MORE -VE means B COM comming CLOSE to Lift COM)
                                                            diff_force_a_lift : force on A - FORCE on Lift
                                                            (MORE +VE means A COM comming CLOSE to Lift COM)
                                                            */

    
    
    int max_height_to_check = 600;



    for(int i=max_height_to_check;i>=height_com;i--)    // till it touches the ground.
    {
        res_g_lift[i] = ((pow(R,2)/pow(R+i,2))*g);   // g value for lift 
        res_g_a[i] = ((pow(R,2)/pow(R+i+Dis_a,2))*g);  // g value for point a(100km above COM)
        res_g_b[i] = ((pow(R,2)/pow(R+i+Dis_b,2))*g);  // g value for point b(100km below COM)
        force_a[i] = res_g_a[i]*WT_a;                   //force on A COM
        force_b[i] = res_g_b[i]*WT_b;                   // force on B COM
        force_lift[i] = res_g_lift[i]*WT_lift;          // force on lift COM
        diff_force_a_lift[i] = force_a[i] - force_lift[i]; // Force diffirence b/w A and Lift COM
        diff_force_b_lift[i] = force_b[i] - force_lift[i]; // Force diffirence b/w B and Lift COM
    }
    /* g Values for 
                     a , 
                     b and 
                     lift
    */
    cout<<"\t\t\t g Value for A FROM FALLING TILL TOUCHDOWN\n\n\n";
    for(int i=max_height_to_check;i>=height_com;i--)
        cout<<res_g_a[i]<<" ";
    cout<<endl;
    cout<<"\t\t\t g Value for B FROM FALLING TILL TOUCHDOWN\n\n\n";
    for(int i=max_height_to_check;i>=height_com;i--)
        cout<<res_g_b[i]<<" ";
    cout<<endl;
    cout<<"\t\t\t g Value for Lift FROM FALLING TILL TOUCHDOWN\n\n\n";
     for(int i=max_height_to_check;i>=height_com;i--)
        cout<<res_g_lift[i]<<" ";
    cout<<endl;
    /* Force Values for 
                     a , 
                     b and 
                     lift
    */
    cout<<"\t\t\t Force Value for A FROM FALLING TILL TOUCHDOWN\n\n\n";
     for(int i=max_height_to_check;i>=height_com;i--)
        cout<<force_a[i]<<" ";
    cout<<endl;
    cout<<"\t\t\t Force Value for B FROM FALLING TILL TOUCHDOWN\n\n\n";
     for(int i=max_height_to_check;i>=height_com;i--)
        cout<<force_b[i]<<" ";
    cout<<endl;
     cout<<"\t\t\t Force Value for Lift FROM FALLING TILL TOUCHDOWN\n\n\n";
     for(int i=max_height_to_check;i>=height_com;i--)
        cout<<force_lift[i]<<" ";
    cout<<endl;
    cout<<"\t\t\t\n Force diffirence b/w A COM and Lift COM FROM FALLING TILL TOUCHDOWN \n\n\n";
    for(int i=max_height_to_check;i>=height_com;i--)
        cout<<diff_force_a_lift[i]<<" ";
    cout<<endl;
    cout<<"\t\t\t\n Force diffirence b/w B COM and Lift COM FROM FALLING TILL TOUCHDOWN \n\n\n";
    for(int i=max_height_to_check;i>=height_com;i--)
        cout<<diff_force_b_lift[i]<<" ";
    cout<<endl;
    
    
    return 0;
}