#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long ll;
const int MAX_N = 400088;

int primes[34000], pcnt;
bool used[MAX_N];
void get_primes();

int main()
{
    get_primes();

    int n, x, cnt1 = 0, cnt2 = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        if (x == 1)
        {
            ++cnt1;
        }
        else
        {
            ++cnt2;
        }
    }
    int sum = 0, ans = 0;
    for (int i = 0; cnt1 | cnt2; i++)
    {
        const int &cur = primes[i];
        while (cur > sum)
        {
            if (cur - sum > 1 && cnt2)
            {
                sum += 2;
                --cnt2;
                printf("2 ");
            }
            else if (cnt1)
            {
                ++sum;
                --cnt1;
                printf("1 ");
            }
            else
                break;
        }
        if (sum == cur)
        {
            ++ans;
        }
    }
    return 0;
}

void get_primes()
{
    for (int i = 2; i < MAX_N; i++)
    {
        if (!used[i])
        {
            primes[pcnt++] = i;
            for (int j = i << 1; j < MAX_N; j += i)
            {
                used[j] = true;
            }
        }
    }
}