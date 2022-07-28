BEGIN {
    population["Sakai"] = 830000;
    population["Kyoto"] = 1470000;
    population["Kobe"] = 1540000;
    ID[1] = "Oda";
    ID[2] = "Toyotomi";
    ID[3] = "Tokugawa";
}

END {
for (i in population) {
    print i": "population[i];
}
for (j = 1; j <= 3; j++) {
    print "ID"j": "ID[j];
}
}