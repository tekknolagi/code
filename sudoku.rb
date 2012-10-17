def segment_valid?(seg)
  (1..9).each{|num|
    if not seg.include? num.to_s
      return false
    end
  }
  return true
end

def section_valid?(section)
  section.each {|seg|
    if not segment_valid? seg
      return false
    end
  }
  return true
end

def puzzle_valid?(horiz, vert, squares)
  return section_valid?(horiz) && section_valid?(vert) && section_valid?(squares)
end

string = "248395716571628349936741582682539174359174628714862953863417295195286437427953861"

horiz = string.scan /.{9}/m
vert = []

(0..8).each {|i|
  a = []
  horiz.each {|row|
    a.push row[i]
  }
  vert.push(a.join "")
}

squares = []

(1..3).each {|i|
  a = []
  horiz.each {|r|
    a.push r[3*i-3..3*i-1]
  }
  squares.push a
}

a = []
squares.each {|r|
  a.push r.each_slice(3).to_a
}
squares = a

a = []
squares.each {|r|
  b = []
  r.each {|q|
    b.push(q.join "")
  }
  a.push b
}
squares = a.flatten

puts puzzle_valid?(horiz, vert, squares)
