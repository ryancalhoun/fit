require 'emplace'

cppunit = Emplace::Project.new 'cppunit',
  url: 'https://github.com/ryancalhoun/cppunit/releases/download/',
  version: 'v1.14.0-9'

project = Emplace::Project.new 'fit'

task :cppunit do
  cppunit.fetch!
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
