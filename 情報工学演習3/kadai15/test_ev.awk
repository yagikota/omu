BEGIN {
    print "FS:", FS;
    print "ARGC:", ARGC;
    for (i in ARGV) {
        print "ARGV["i"]:", ARGV[i]
    }
}

{
    print "NR:", NR, " $1:", $1;
}

END {
}
