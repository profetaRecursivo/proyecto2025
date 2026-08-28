#define ll long long
ll B;
ll BINV;
const ll MOD = 2305843009213693951LL;
inline ll mulmod(ll a, ll b){
    return (ll)((__int128_t)a*b%MOD);
}
struct Hash{
    ll h, b, bi;
    Hash(ll _h = 0, ll _b = 1, ll _bi =1):h(_h), b(_b), bi(_bi){}
    Hash operator*(const Hash& otro){
        return Hash((h + mulmod(b, otro.h))%MOD, mulmod(b, otro.b), mulmod(bi, otro.bi));
    }
    Hash operator/(const Hash&otro){
        return Hash(mulmod(((h - otro.h + 2*MOD)%MOD),otro.bi), mulmod(b, otro.bi), mulmod(bi, otro.b));
    }
    Hash operator+(char c){
        return Hash((h + mulmod(b, (c-'a'+1+MOD)%MOD))%MOD, mulmod(b, B), mulmod(bi, BINV));
    }
    
};
void inicializar_hash(){
    mt19937_64 generador(chrono::steady_clock::now().time_since_epoch().count());
    B = 257 + (generador() % (MOD - 300));
    BINV = expmod(B, MOD - 2);
}