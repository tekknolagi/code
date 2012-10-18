def in_order?(num)
  s = num.to_s
  t=0
  s.each_char {|char|
    if char.to_i > t
      t=char.to_i
    else
      return false
    end
  }
  return true
end

count=0
for i in (ARGV[0]..ARGV[1])
  if in_order?(i.to_s)
    count += 1
  end
end
puts count
