BEGIN {
    height = 0;
}
{
    field = 1
if ($field == "Taro") {
    height = $2;
}
}
END {
    print "Taro's height: " height;
    print
}
