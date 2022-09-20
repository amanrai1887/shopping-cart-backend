#include<iostream> 
#include<vector>
#include "datamodel.h"
using namespace std;

vector<Product> allProducts={
     Product(1,"Apple",20),
     Product(3,"Mango",21),
     Product(2,"guava",30),
     Product(5,"banana",45),
     Product(4,"straberry",29),
     Product(6,"pineapple",36),
};

Product* chooseProduct(){

string productList;
cout<<"Available Product"<<endl;
for(auto product : allProducts){
    productList.append(product.getDisplayName());
}
cout<<productList<<endl;
cout<<".................."<<endl;;
string choice;
cin>>choice;
for(int i=0;i< allProducts.size();i++){
    if(allProducts[i].getShortName()==choice){
        return &allProducts[i];
    }
}
cout<<"product not found"<<endl;
return NULL;
}
bool checkout(Cart &cart){
    if(cart.isEmpty()){
        return false;
    }
    int total = cart.getTotal();
    cout<<"Pay in cash ";
    int paid;
    cin>>paid;
    if(paid>=total){
        cout<<"change"<<paid-total<<endl;
        cout<<"thanks for shopping";
        return false;

    }else{
        cout<<"not enough cash !";
        return false;
    }

}
int main(){

    char action;
    Cart cart;
    while(true){
       
     cout<<"select an action - (a)dd item, (v)iew cart, (c)heckout"<<endl;
     cin>>action;
     if(action== 'a'){
        Product* product=chooseProduct();
        if(product!=NULL){
            cout<<"Added to cart "<<product->getDisplayName()<<endl;
            cart.addProduct(*product);
        }

     }
     else if(action=='v'){
         cout<<"------------------"<<endl;
         cout<<cart.viewcart();
         cout<<"-------------------"<<endl;



     }else {
     cart.viewcart();
     if(checkout(cart)){
        break;
     }
    }
    }
    
    return 0;
}