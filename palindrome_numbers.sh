 #!/bin/bash
start=$1
end=$2
for((i=start;i<=end;i++));
do
        reverse=$(echo "$i"|rev)
        if [ "$reverse" -eq "$i" ]; then
                echo "$i"
        fi
done
