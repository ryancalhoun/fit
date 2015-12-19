require 'emplace'

cppunit = Emplace::Project.new 'cppunit'
project = Emplace::Project.new 'fit'

task :cppunit do
  url = 'https://github.com/ryancalhoun/cppunit/releases/download/v1.14.0-7/'
  cppunit.fetch! url
  cppunit.extract!
end

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
