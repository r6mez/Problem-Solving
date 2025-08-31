# https://codeforces.com/problemset/problem/893/C

$n, $m = gets.split.map(&:to_i)

$val = []
$val.concat(gets.split.map(&:to_i))

$adj = Array.new($n) { [] }
$m.times do
  u, v = gets.split.map(&:to_i)
  u -= 1
  v -= 1
  $adj[u] << v
  $adj[v] << u
end

$vis = Array.new($n, false)

def dfs(u, min = 1 << 60)
  stack = [u]
  $vis[u] = true
  min = 1 << 60
  until stack.empty?
    u = stack.pop
    min = [$val[u], min].min
    $adj[u].each do |v|
      next if $vis[v]
      $vis[v] = true
      stack << v
    end
  end
  return min
end

sum = 0
(0..$n - 1).each do |i|
  if $vis[i] == false
    sum += dfs(i)
  end
end

puts sum
