JAVA_HOME=/usr/lib/jvm/default-java
M2_HOME=/opt/maven
MAVEN_HOME=/opt/maven
PATH=${M2_HOME}/bin:${PATH}
# mvn dependency:copy-dependencies -Dclassifier=sources
mvn package