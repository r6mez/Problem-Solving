# https://codeforces.com/problemset/problem/292/B

n, m = gets.split.map(&:to_i)

deg = Array.new(n + 1, 0)

m.times do
  u, v = gets.split.map(&:to_i)
  deg[u] += 1
  deg[v] += 1
end


one = 0
two = 0
other = 0

(1..n).step(1) do |x|
  if deg[x] == 1
    one += 1
  elsif deg[x] == 2
    two += 1
  else 
    other += 1
  end  
end

if one == 2 and two == n - 2
  puts "bus topology"
elsif two == n 
  puts "ring topology"
elsif one == n - 1 and other == 1
  puts "star topology"
else
  puts "unknown topology"
end