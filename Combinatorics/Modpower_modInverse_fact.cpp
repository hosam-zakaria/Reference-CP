const ll N = 2e6+3;
ll fpow(ll b, ll p, ll m){
    if(p == 0){return 1;}
    ll half = fpow(b, p>>1, m)%m;
    return (p&1? ((half * half)%m * b) : (half * half))%m;
}
/* ===================================================== */
// (A/B)%m --> )(A%m)*mod_inv(b))%m Where m must be prime
ll mod_inv(ll x,ll mod) {
    return fpow(x,mod-2,mod); // must mod be prime
}
/* ===================================================== */
ll fact[N];
void factorial(ll mod){
    fact[0]=fact[1]=1;
    for(ll i=2;i<N;i++){
        fact[i]=(fact[i-1]*(i%mod))%mod;
    }
}
ll nPr(ll n ,ll r,ll mod) { return fact[n]*mod_inv(fact[n-r],mod)%mod; }
ll nCr(ll n ,ll r, ll mod) {
    return fact[n]*mod_inv(fact[r]*fact[n-r]%mod,mod)%mod;
}
