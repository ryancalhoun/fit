require 'emplace'

project = Emplace::Project.new 'fit'

task :clean do
  project.clean!
end

task :cmake do
  project.cmake!
end

task :build do
  project.build!
end

task :package do
  project.package!
end

task :test do
  project.test!
end

task :default => [:cmake, :build, :test, :package]
