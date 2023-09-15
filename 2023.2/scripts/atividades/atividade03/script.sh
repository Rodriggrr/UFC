grep -v 'sshd' auth.log
grep -E 'sshd.*Accepted.*\bj' auth.log
grep -E 'sshd.*Disconnected.*root' auth.log
grep -E 'Oct (11|12).*(CRON|sshd).*(opened|publickey)' auth.log
