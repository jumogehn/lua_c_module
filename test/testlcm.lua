
local fs = require "lcm.fs"

local files = fs.dir("./")

for i=1, #files do
  print(files[i])
end

