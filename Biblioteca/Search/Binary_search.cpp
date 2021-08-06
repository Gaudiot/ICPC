vll vec; //The vec array must be sorted in order to the binary search  to work
bool binary_search(ll val){
    ll l = 0; //Set minimum value here
    ll r = vec.size()-1; // Set maximum value here

    while(l < r){
        ll m = (l+r)/2;
        if(vec[m] == val){
            return true;
        }else if(vec[m] > val){
            r = m-1;
        }else if(vec[m] < val){
            l = m+1;
        }
    }

    return false;
}