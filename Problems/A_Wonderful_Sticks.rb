# Solving https://codeforces.com/contest/2096/problem/A

t = gets.to_i

t.times do
  n = gets.to_i
  s = gets.chomp
  gCnt = 0

  s.chars.each do |ch|
    gCnt += 1 if ch == '>'
  end

  r = n - gCnt + 1
  l = r - 1

  arr = Array.new(n, 0)
  arr[0] = l
  l -= 1

  (1..n - 1).step(1) do |i|
    if s.chars[i - 1] == '>'
      arr[i] = r
      r += 1
    else
      arr[i] = l
      l -= 1
    end
  end

  arr.each do |x|
    print "#{x} "
  end

  puts ''
end