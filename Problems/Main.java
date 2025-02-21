/*
I thought I could bring an end to the world's suffering,
But when every equation was solved,
all that remained were fields of dreamless solitude.
*/

// A - Knapsack 1
// URL: https://vjudge.net/contest/694790#problem/A
// Time: 2/20/2025, 11:08:38 PM

import java.io.*;
import java.util.*;

import java.util.AbstractMap.SimpleEntry;

public class Main {
    static final long MOD = 1_000_000_007;
    static final FastReader in = new FastReader();
    static final PrintWriter out = new PrintWriter(System.out);

    static int n, w;
    static ArrayList<SimpleEntry<Integer, Integer>> items = new ArrayList<>();

    static int dp(int i, int weight) {
        if(i == n) return 0;
        if(weight < items.get(i).getKey()) return dp(i + 1, weight);
        return Math.max(dp(i + 1, weight), dp(i + 1, weight - items.get(i).getKey()));
    }

    static void solve() {
        n = in.nextInt();
        w = in.nextInt();
        for (int i = 0; i < n; i++) {
            int weight = in.nextInt();
            int value = in.nextInt();
            items.add(new SimpleEntry<>(weight, value));
        }

        out.println(dp(0, w));
    }
    
    public static void main(String[] args) {
        // UseFile();
        int t = 1;
        // t = in.nextInt();
        while (t-- > 0) solve();
        out.flush();
    }
    
    static void UseFile() {
        try {
            System.setIn(new FileInputStream("file.in"));
            System.setOut(new PrintStream("file.out"));
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;
        
        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }
        
        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
        
        int nextInt() { return Integer.parseInt(next()); }
        long nextLong() { return Long.parseLong(next()); }
        double nextDouble() { return Double.parseDouble(next()); }
        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
}
