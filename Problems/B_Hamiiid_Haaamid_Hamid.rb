# https://codeforces.com/problemset/problem/2127/B

t = gets.to_i

t.times do
  n, k = gets.split.map(&:to_i)
  s = gets.chomp

  left = 0
  right = n + 1

  (k - 2).downto(0) do |i|
    if s[i] == '#'
      left = i + 1
      break
    end
  end

  k.upto(n - 1) do |i|
    if s[i] == '#'
      right = i + 1
      break
    end
  end

  a = [k, n - right + 2].min
  b = [left + 1, n - k + 1].min
  puts [a, b].max
end
