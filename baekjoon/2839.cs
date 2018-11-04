using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cSharP_3839Sugar
{
    class Program
    {
        static void Main(string[] args)
        {
            int N = Convert.ToInt32(Console.ReadLine());
            int[] dp = new int[5007];
            int[] coin = { 3, 5 };
            for (int i = 0; i <= 5006; i++)
                dp[i] = 5001;
            dp[0] = 0;
            for(int i = 0; i<=N; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    if (dp[i + coin[j]] > dp[i] + 1)
                        dp[i + coin[j]] = dp[i] + 1;
                }
            }
            if (dp[N] != 5001)
                Console.WriteLine(dp[N]);
            else
                Console.WriteLine("-1");
        }
    }
}
