/*
I thought I could bring an end to the world's suffering,
But when every equation was solved,
all that remained were fields of dreamless solitude.
*/

// {{problemName}}
// URL: {{problemURL}}
// Time: {{time}}

import java.io.*;
import java.util.*;

public class Main {
    static final long MOD = 1_000_000_007;
    static final FastReader in = new FastReader();
    static final PrintWriter out = new PrintWriter(System.out);
    
    static void solve() {
        
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
